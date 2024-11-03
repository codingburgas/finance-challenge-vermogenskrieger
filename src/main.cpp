#include <QApplication>
#include "mainwindow.h"
#include <QSystemTrayIcon>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    QIcon appIcon("fullLogo.ico");

    QString darkThemeStyle = R"(
    QWidget {
        background-color: #2e2e2e; /* Dark background */
        color: #ffffff; /* White text */
    }
    QLineEdit, QTextEdit, QTextBrowser {
        background-color: #3c3c3c; /* Input fields */
        color: #ffffff; /* Input text */
    }
    QPushButton {
        background-color: #4c4c4c; /* Button background */
        color: #ffffff; /* Button text */
        border: 1px solid #5c5c5c; /* Button border */
    }
    QPushButton:hover {
        background-color: #5c5c5c; /* Button hover */
    }
    QLabel {
        color: #ffffff; /* Label text */
    }
)";


    w.setStyleSheet(darkThemeStyle);

    a.setWindowIcon(appIcon);
    QSystemTrayIcon trayIcon;
    trayIcon.setIcon(appIcon);

    w.setWindowTitle("Vermögenskrieger");

    trayIcon.show();

    w.show();
    return a.exec();
}
