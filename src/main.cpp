#include <QApplication>
#include "mainwindow.h"
#include <QSystemTrayIcon>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    QIcon appIcon("fullLogo.ico");

    a.setWindowIcon(appIcon);
    QSystemTrayIcon trayIcon;
    trayIcon.setIcon(appIcon);

    w.setWindowTitle("Vermögenskrieger");

    trayIcon.show();

    w.show();
    return a.exec();
}
