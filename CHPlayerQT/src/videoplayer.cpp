#include "videoplayer.h"
#include <QFileDialog>
#include <QMessageBox>

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent), vlcInstance(nullptr), mediaPlayer(nullptr)
{
    ui.setupUi(this);

    // Initialize VLC
    const char *vlc_args[] = {
        "--no-xlib"
    };
    vlcInstance = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);
    if (!vlcInstance) {
        QMessageBox::critical(this, "VLC Error", "Failed to create VLC instance.");
        return;
    }

    mediaPlayer = libvlc_media_player_new(vlcInstance);
    libvlc_media_player_set_hwnd(mediaPlayer, reinterpret_cast<void*>(ui.videoWidget->winId()));

    // Connect the play button
    connect(ui.playButton, &QPushButton::clicked, this, &VideoPlayer::playVideo);
}

VideoPlayer::~VideoPlayer()
{
    if (mediaPlayer)
        libvlc_media_player_release(mediaPlayer);
    if (vlcInstance)
        libvlc_release(vlcInstance);
}

void VideoPlayer::playVideo()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Video File");
    if (filePath.isEmpty())
        return;

    libvlc_media_t *media = libvlc_media_new_path(vlcInstance, filePath.toUtf8().constData());
    libvlc_media_player_set_media(mediaPlayer, media);
    libvlc_media_release(media);
    libvlc_media_player_play(mediaPlayer);
}
