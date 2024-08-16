/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Video_File;
    QAction *actionLoad_Audio_File;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionAudio_Output;
    QAction *actionfullScreen;
    QAction *actioninfoScreen;
    QWidget *centralwidget;
    QFrame *videoFrame;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 749);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::Europe));
        MainWindow->setTabShape(QTabWidget::Triangular);
        actionLoad_Video_File = new QAction(MainWindow);
        actionLoad_Video_File->setObjectName("actionLoad_Video_File");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/My-Videos-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Video_File->setIcon(icon1);
        actionLoad_Audio_File = new QAction(MainWindow);
        actionLoad_Audio_File->setObjectName("actionLoad_Audio_File");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/My-Music-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Audio_File->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionAudio_Output = new QAction(MainWindow);
        actionAudio_Output->setObjectName("actionAudio_Output");
        actionfullScreen = new QAction(MainWindow);
        actionfullScreen->setObjectName("actionfullScreen");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/Full_screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfullScreen->setIcon(icon3);
        actionfullScreen->setMenuRole(QAction::NoRole);
        actioninfoScreen = new QAction(MainWindow);
        actioninfoScreen->setObjectName("actioninfoScreen");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/information-emblem.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioninfoScreen->setIcon(icon4);
        actioninfoScreen->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        videoFrame = new QFrame(centralwidget);
        videoFrame->setObjectName("videoFrame");
        videoFrame->setGeometry(QRect(0, 0, 961, 621));
        videoFrame->setFrameShape(QFrame::StyledPanel);
        videoFrame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad_Video_File);
        menuFile->addAction(actionLoad_Audio_File);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionAudio_Output);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionLoad_Video_File);
        toolBar->addAction(actionLoad_Audio_File);
        toolBar->addAction(actionfullScreen);
        toolBar->addAction(actioninfoScreen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CHPlayer", nullptr));
#if QT_CONFIG(statustip)
        MainWindow->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        actionLoad_Video_File->setText(QCoreApplication::translate("MainWindow", "Load Video File", nullptr));
        actionLoad_Audio_File->setText(QCoreApplication::translate("MainWindow", "Load Audio File", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionAudio_Output->setText(QCoreApplication::translate("MainWindow", "Audio Output", nullptr));
        actionfullScreen->setText(QCoreApplication::translate("MainWindow", "fullScreen", nullptr));
        actioninfoScreen->setText(QCoreApplication::translate("MainWindow", "infoScreen", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "Setup", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
