#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include "qpushbutton.h"
#include "qslider.h"
#include "qtimer.h"
#include <QMainWindow>
#include <vlc/vlc.h>
#include <QResizeEvent>
#include <QWidget>
#include <QMouseEvent>
#include <QComboBox>
#include <QMediaPlayer>
#include <QAudioDevice>
#include <QAudioOutput>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


private:
    QPushButton *statusBarButton;

private slots:
    void updateUI();


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadMedia(const QString &mediaPath);
    void loadAudio(const QString &audioPath);
    void onPlayPauseClicked();
    void onStopClicked();
    void onVolumeChanged(int value);
    void onMuteClicked();
    void on_actionAbout_triggered();
    void on_actionfullScreen_triggered();
    void on_actioninfoScreen_triggered();

protected:
    void keyPressEvent(QKeyEvent *event) override;

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    void play();

private:
    void pause();

private:
    void stop();

private:
    void loadToolicons();

private:
    void setPosition(int position);

private:
    void showFullScreenMode();

private:
    void setTopFrameWidthToScreenSize();

private:
    void clearVideoFrame();

private:
    void updateAudioOutput();

private:
    void onAudioOutputChanged();

private:
    void getVolume();


private:
    Ui::MainWindow *ui;
    libvlc_instance_t *vlcInstance;
    libvlc_media_player_t *vlcMediaPlayer;
    QFrame *videoFrame;
    QPushButton *BtFullscreen;
    bool isFullScreen = false;
    QPushButton *playPauseButton;
    QPushButton *stopButton;
    QLabel *currentTimeLabel;
    QLabel *curAudioTimeLabel;
    QLabel *totalTimeLabel;
    QSlider *progressSlider;
    QSlider *volumeSlider;
    QPushButton *muteButton;
    QTimer *timer;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString filePath;
    QComboBox *outputAudioComboBox;
    bool audio = false;
    QString videoFile;
    QString audioFile;


};

#endif // MAINWINDOW_H


