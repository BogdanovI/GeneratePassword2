#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedSize(490, 200);
    return a.exec();
}
