#include <QApplication>
#include "mainwindow.h"
#include <QSystemTrayIcon>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    #ifdef Q_OS_WINDOWS
        QIcon appIcon("C:/Users/anton/source/repos/finance-challenge-vermogenskrieger/src/images/fullLogo.ico");
    #else
       QIcon appIcon("images/fullLogo.ico");
    #endif

    a.setWindowIcon(appIcon);
    QSystemTrayIcon trayIcon;
    trayIcon.setIcon(appIcon);

    w.setWindowTitle("Vermögenskrieger");

    trayIcon.show();

    w.show();
    return a.exec();
}
