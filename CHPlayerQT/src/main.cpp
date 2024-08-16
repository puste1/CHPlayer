#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
//#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("CHPLayer QT");
    w.show();
    return a.exec();
}
