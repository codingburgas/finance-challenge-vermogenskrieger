#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "login.h"
#include "register.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showLogin();
    void showRegister();
    void showLoginFromRegister(); // Ensure this line exists

private:
    Ui::MainWindow *ui;
    Login *loginPage;
    RegisterForm *registerPage;
};

#endif // MAINWINDOW_H
