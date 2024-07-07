#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileDialog>
#include <QMessageBox>
#include <QUrl>
#include <QDebug>
#include <QFrame>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStyleOptionButton>
#include <QTimer>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QAudioDevice>
#include <QSoundEffect>
#include <QAudioOutput>
#include <QMediaDevices>
#include <QAudioDevice>
#include <QAudioSink>
#include <QCoreApplication>



//**************************************************************************************
// Main Window Widget
//**************************************************************************************
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), vlcMediaPlayer(nullptr)
{
    ui->setupUi(this);

    // Initialize the VLC media player
    vlcInstance = libvlc_new(0, nullptr);
    vlcMediaPlayer = libvlc_media_player_new(vlcInstance);

    // Warning Window
    QWidget window;


    // Create media control widgets
    playPauseButton = new QPushButton("▶", this);
    playPauseButton->setFixedSize(30, 30); // Set fixed size for the play/pause button
    connect(playPauseButton, &QPushButton::clicked, this, &MainWindow::onPlayPauseClicked);

    // Create the media player
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);

    // Stop Botton
    stopButton = new QPushButton("■", this);
    stopButton->setFixedSize(30, 30); // Set fixed size for the stop button
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::onStopClicked);

    // Mute Botton
    muteButton = new QPushButton("🔊", this);
    muteButton->setFixedSize(30, 30); // Set fixed size for the play/pause button
    connect(muteButton, &QPushButton::clicked, this, &MainWindow::onMuteClicked);

    // Volume Slider
    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setFixedSize(80,30); // Set fixed size for the play/pause button
    volumeSlider->setRange(0, 100); // Minimum value = 0, Maximum value = 100
    volumeSlider->setValue(volumeSlider->maximum());

    // Progress Slider
    progressSlider = new QSlider(Qt::Horizontal, this);
    progressSlider->setFixedSize(600,30); // Set fixed size for the play/pause button

    // Time Current and Total
    currentTimeLabel = new QLabel("00:00:00", this);
    curAudioTimeLabel = new QLabel("00:00:00", this);
    totalTimeLabel = new QLabel("00:00:00", this);

    // Create a layout for the media controls
    QWidget *mediaControlWidget = new QWidget(this);
    QHBoxLayout *mediaLayout = new QHBoxLayout(mediaControlWidget);
    mediaLayout->addWidget(playPauseButton);
    mediaLayout->addWidget(stopButton);
    mediaLayout->addWidget(currentTimeLabel);
    mediaLayout->addWidget(curAudioTimeLabel);
    mediaLayout->addWidget(progressSlider);
    mediaLayout->addWidget(totalTimeLabel);
    mediaLayout->addWidget(muteButton);
    mediaLayout->addWidget(volumeSlider);
    mediaLayout->setContentsMargins(0, 0, 0, 0);
    mediaControlWidget->setLayout(mediaLayout);

    // Add the media controls to the status bar
    statusBar()->addPermanentWidget(mediaControlWidget);


    // Initialize LibVLC
    vlcInstance = libvlc_new(0, nullptr);
    if (!vlcInstance) {
        qDebug() << "LibVLC initialization failed.";
        return;
    }

    // Create a new media player
    vlcMediaPlayer = libvlc_media_player_new(vlcInstance);
    if (!vlcMediaPlayer) {
        qDebug() << "LibVLC media player creation failed.";
        return;
    }

    // Ensure the QFrame is visible and properly configured
    //QFrame *topFrame = ui->topFrame;
    QFrame *videoFrame = ui->videoFrame;
    videoFrame->setAttribute(Qt::WA_OpaquePaintEvent);
    videoFrame->show();

    // Initial setup
    setTopFrameWidthToScreenSize();

    // Create a layout and set it for the central widget
    QVBoxLayout* layout = new QVBoxLayout(this);


    // Add the QFrame to the layout
    layout->addWidget(videoFrame);

    //videoFrame->setFixedHeight(600); // Set a fixed height for the video frame
    layout->setContentsMargins(0, 0, 0, 0); // Adjust the margins as needed


    // Get the native window handle (X11 on Linux)
    qDebug() << "videoFrame winId:" << videoFrame->winId();
    libvlc_media_player_set_xwindow(vlcMediaPlayer, videoFrame->winId());

    // Set Default Dir to User's Home Directory
    QString defaultDir = QDir::homePath();

    //*******************************************************************
    // Connect the play button to playMedia function
    //*******************************************************************


    // Using a lambda with explicit capture of defaultDir
    auto openVideoFile = [this, defaultDir]() {
        videoFile = "";
        audioFile = "";
        QString mediaPath = QFileDialog::getOpenFileName(this, tr("Open Media"), defaultDir, tr("Video Files (*.mp4 *.mpeg1 *.mpeg2 *.mov *.ts *.ogv *.AVI *.3GP *.VLC);;All files(*)"));
        if (!mediaPath.isEmpty()) {
            loadMedia(mediaPath);
            // Save Video Filename for Info
            QFileInfo fileInfo(mediaPath);
            videoFile = fileInfo.fileName();

            // Get mp3 file same as videofile name if exist.
            QString directoryPath = fileInfo.absolutePath();
            QString mp3Name = directoryPath + '/' + fileInfo.completeBaseName() + ".mp3";  // Extract the filename without extension
            qDebug() << "Base name without extension:" << mp3Name;
            if (QFile::exists(mp3Name)) {
                loadAudio(mp3Name);
                // Save Audio Filename for Info
                QFileInfo fileInfo(mp3Name);
                audioFile = fileInfo.fileName();
                audio = true;
                // Change to default Output Audio
                onAudioOutputChanged();
            } else {
                // Get Default mp3 e-stim Audio File the first mp3 in dir
                QDir dir(directoryPath);
                // Set the name filters to match .mp3 files
                QStringList nameFilters;
                nameFilters << "*.mp3";

                // Get the list of .mp3 files
                QStringList mp3Files = dir.entryList(nameFilters, QDir::Files);
                // Return the first .mp3 file
                QString firstMp3File = dir.absoluteFilePath(mp3Files.first());
                qDebug() << "first MP3 file:" <<  firstMp3File;
                if (QFile::exists(firstMp3File)) {
                    loadAudio(firstMp3File);
                    // Save Audio Filename for Info
                    QFileInfo fileInfo(firstMp3File);
                    audioFile = fileInfo.fileName();
                    audio = true;
                    // Change to default Output Audio
                    onAudioOutputChanged();
                }
            }
        }
    };


    // Connect the button to the function
    connect(ui->OpenVideo, &QPushButton::clicked, openVideoFile);
    // Conenct Use Menu to Load Video File
    connect(ui->actionLoad_Video_File, &QAction::triggered, openVideoFile);

    //********************************************************************
    // initialization function play Audio function
    //********************************************************************
    auto openAudioFile = [this, defaultDir]() {
        audioFile = "";
        QString audioPath = QFileDialog::getOpenFileName(this, tr("Select Audio File"), defaultDir, tr("Audio files (*.mp3 *.flac *.wav *.aiff *.ogg);;All files(*)"));
        if (!audioPath.isEmpty()) {
            loadAudio(audioPath);
            QFileInfo fileInfo(audioPath);
            audioFile = fileInfo.fileName();
            audio = true;
            onAudioOutputChanged();
        } else {
            audio = false;
            QMessageBox::warning(this, "No File Selected", "Please select an audio file to play.");
        }
    };

    // Connect the button to the function
    connect(ui->OpenAudio, &QPushButton::clicked, openAudioFile);
    // Conenct Use Menu to Load Audio File
    connect(ui->actionLoad_Audio_File, &QAction::triggered, openAudioFile);


    // Connect audio output combo box
    connect(ui->audioOutputComboBox, &QComboBox::currentTextChanged, this, &MainWindow::updateAudioOutput);

    // Retrieve available audio output devices also called Populate audio output devices
    const QList<QAudioDevice> audioDevices = QMediaDevices::audioOutputs();

    // Put the Populate audio output devices to combobox
    for (const QAudioDevice &device : audioDevices) {
        ui->audioOutputComboBox->addItem(device.description(), QVariant::fromValue(device));
    }

    // Set select Audio
    connect(ui->audioOutputComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onAudioOutputChanged);

    //onAudioOutputChanged();
    //QAudioDevice info(QMediaDevices::defaultAudioOutput());



    //************************************************************************
    // Connect Fullscreen Botton
    //************************************************************************
    connect(ui->BtFullscreen, &QPushButton::clicked, this, &MainWindow::toggleFullscreen);

    // Connect volume slider
    //connect(volumeSlider, &QSlider::valueChanged, this, &MainWindow::setVolume);

    // Update seek slider and time labels periodically
    QTimer *timer = new QTimer(this);

    // Connect the timer to the updateUI slot
    connect(timer, &QTimer::timeout, this, &MainWindow::updateUI);

    // Start the timer with an interval of 1000 ms (1 second)
    timer->start(1000); // Update every second

    //************************************************************************
    // Connect seek slider
    //************************************************************************
    connect(progressSlider, &QSlider::sliderMoved, this, &MainWindow::setPosition);

    //************************************************************************
    // Exit Application
    //************************************************************************
    connect(ui->actionExit, &QAction::triggered, qApp, &QCoreApplication::quit);

    getVolume();

}

//**************************************************************************************
// Main Window
//**************************************************************************************
MainWindow::~MainWindow()
{
    // Release LibVLC resources
    libvlc_media_player_stop(vlcMediaPlayer);
    libvlc_media_player_release(vlcMediaPlayer);
    libvlc_release(vlcInstance);
    delete ui;
}

//**************************************************************************************
// Load Video File to VLC
//**************************************************************************************
void MainWindow::loadMedia(const QString &mediaPath)
{
    // Create a new media
    libvlc_media_t *media = libvlc_media_new_path(vlcInstance, mediaPath.toStdString().c_str());
    if (!media)
    {
        qWarning("Failed to create media.");
        return;
    }

    // Set the media to the media player
    libvlc_media_player_set_media(vlcMediaPlayer, media);

    // Release the media
    libvlc_media_release(media);
}

//**************************************************************************************
// Load Audio File
//**************************************************************************************
void MainWindow::loadAudio(const QString &audioPath)
{
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    // Set Audio File name to play
    player->setSource(QUrl::fromLocalFile(audioPath));
    // Set volume
    audioOutput->setVolume(10);  // Set the volume (0.0 to 1.0)
}


//**************************************************************************************
// Play/Pause
//**************************************************************************************
void MainWindow::onPlayPauseClicked()
{
    // Toggle play/pause
    if (playPauseButton->text() == "▶") {
        if (audio) {
            playPauseButton->setText("⏸");
            // Start playing Video on VLC
            libvlc_media_player_play(vlcMediaPlayer);
            // Start playing Adio in QT
            player->play();
        } else {
            QMessageBox::warning(this, "No File Selected", "Please select an audio file to play.");
        }
    } else {
        playPauseButton->setText("▶");
        // Pause Video on VLC
        libvlc_media_player_pause(vlcMediaPlayer);
        // Pause Audio on QT
        player->pause();
    }
}

//**************************************************************************************
// Stop
//**************************************************************************************
void MainWindow::onStopClicked()
{
    if (playPauseButton->text() == "⏸") {
        playPauseButton->setText("▶");
        // Stop Video on VLC
        libvlc_media_player_stop(vlcMediaPlayer);
        // Stop Audio on QT
        player->stop();
    }
}

//**************************************************************************************
// Change Video Volume
//**************************************************************************************
void MainWindow::onVolumeChanged(int value)
{
    // Change volume
}

//**************************************************************************************
// Mute Clicked
//**************************************************************************************
void MainWindow::onMuteClicked()
{
    if (muteButton->text() == "🔊") {
        muteButton->setText("🔈");
        // Mute audio
    } else {
        muteButton->setText("🔊");
        // Unmute audio
    }
}

//**************************************************************************************
// Play Video
//**************************************************************************************
void MainWindow::play()
{
    libvlc_media_player_play(vlcMediaPlayer);
}

//**************************************************************************************
// Pause
//**************************************************************************************
void MainWindow::pause()
{
    libvlc_media_player_pause(vlcMediaPlayer);
}

//**************************************************************************************
// Swith from Normal to Fullscreen vs
//**************************************************************************************
void MainWindow::toggleFullscreen()
{
    if (isFullScreen) {
        isFullScreen = false;
        ui->topFrame->show();
        ui->menubar->show();
        ui->videoFrame->setGeometry(0,0,600,800);
        showNormal();
        statusBar()->show();
    } else {
        isFullScreen = true;
        ui->topFrame->hide();
        ui->menubar->hide();
        showFullScreen();
        ui->videoFrame->setGeometry(0, 0, this->width(), this->height());
        // Hide the status bar
        statusBar()->hide();
    }
}

//**************************************************************************************
// Set Video Position with Slider
//**************************************************************************************
void MainWindow::setPosition(int position)
{
    libvlc_media_player_set_time(vlcMediaPlayer, position);
}

//**************************************************************************************
// Set Frame on Top Screen
//**************************************************************************************
void MainWindow::setTopFrameWidthToScreenSize() {
    // Get the screen size
    QRect screenGeometry = QApplication::primaryScreen()->geometry();
    int screenWidth = screenGeometry.width();

    // Set the width of the topFrame to the screen width
    ui->topFrame->setGeometry(0, ui->topFrame->geometry().y(), screenWidth, ui->topFrame->geometry().height());
    // Set the width of the botFrame to the screen width

    // Optionally, adjust the layout to make sure it scales properly
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(ui->topFrame);
    centralWidget()->setLayout(layout);
}

//**************************************************************************************
// Set Video Frame to Resize Window include top Frame
//**************************************************************************************
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    ui->videoFrame->setGeometry(0, 0, event->size().width(), event->size().height());
    // Ensure the topFrame always fits the width of the window
    setTopFrameWidthToScreenSize();
}

//**************************************************************************************
// Escape Key Pressed to exit Fullscreen
//**************************************************************************************
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape && isFullScreen) {
        toggleFullscreen();
    } else {
        QMainWindow::keyPressEvent(event); // Call the base class implementation
    }
}

//**************************************************************************************
// Mouse Botton Pressed to exit Fullscreen
//**************************************************************************************
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isFullScreen)
    {
        toggleFullscreen();
    }
}

//**************************************************************************************
// Update Slider, Current Video/Audio Time and Total Time.
//**************************************************************************************
void MainWindow::updateUI() {
    if (libvlc_media_player_is_playing(vlcMediaPlayer)) {
        int64_t currentTime = libvlc_media_player_get_time(vlcMediaPlayer);
        int64_t curAudioTime = player->position();
        int64_t totalTime = libvlc_media_player_get_length(vlcMediaPlayer);

        progressSlider->setValue(currentTime);
        progressSlider->setMaximum(totalTime);

        currentTimeLabel->setText(QTime(0, 0, 0).addMSecs(currentTime).toString("hh:mm:ss"));
        curAudioTimeLabel->setText(QTime(0, 0, 0).addMSecs(curAudioTime).toString("hh:mm:ss"));
        totalTimeLabel->setText(QTime(0, 0, 0).addMSecs(totalTime).toString("hh:mm:ss"));

        if (qAbs(currentTime - curAudioTime) > 1000) {
            player->setPosition(currentTime);
            qDebug() << "Adjust Audio Time: " << currentTime;
        }
    }
}

//**************************************************************************************
// Update Audio Devices
//**************************************************************************************
void MainWindow::updateAudioOutput() {
    if (ui->audioOutputComboBox->currentIndex() >= 0) {
        //QAudioDevice device = ui->audioOutputComboBox->currentData().value<QAudioDevice>();
        //audioOutput->setDevice(device);
    }
}

//**************************************************************************************
// Change Audio Devices
//**************************************************************************************
void MainWindow::onAudioOutputChanged()
{
    QAudioDevice selectedDevice = ui->audioOutputComboBox->currentData().value<QAudioDevice>();
    qDebug() << "Selected audio device:" << selectedDevice.description();
    audioOutput->setDevice(selectedDevice);
    player->setAudioOutput(audioOutput);
}


//**************************************************************************************
// Show Files open
//**************************************************************************************
void MainWindow::on_OpenInfo_clicked()
{
    QMessageBox::information(this, "File Selected", "Video File: " + videoFile + "\n\nAudio File: " + audioFile);
}

//**************************************************************************************
// Show About
//**************************************************************************************
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    QApplication::setWindowIcon(QIcon(":/XXX.ico")); // from a resource file
    QMessageBox::about(this, "About CHPlyer QT", "CHPlayer QT\n\n"
        "Verion: Beta 1\n\n"
        "Copyright © 2024\n\n"
        "XXXApp\n\n"
        "This Program CH Player QT start embeded VLC Video PLayer\n"
        "with selected Video and E-stim audio File that\n"
        "can be played to a second Audio Device (Ex. USB Audio Card)\n"
        "It uses internal QT Mediaplayer for stream audio to a second audio device.\n"
        "And it is doing an exact syncronisation with the video file\n"
        "Se more at https://milovana.com/forum/");


}

void MainWindow::getVolume()
{

    ui->audioSlider->setRange(0, 100);
    ui->audioSlider->setFixedWidth(100);
    ui->audioSlider->setValue(100);

    connect(ui->audioSlider, SIGNAL(valueChanged(int)), this, SIGNAL(volumeChanged(int)));
    //connect(ui->audioSlider, SIGNAL(valueChanged(int)), player, SLOT(setVolume(int)));

    //int readvolume = player->volume();

    //ui->Volume->setText(QString("Volume: %1").arg(readvolume)); // Display the volume as percentage

}


