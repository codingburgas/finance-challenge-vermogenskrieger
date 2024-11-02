#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "ui_MainWindow.h"
#include "register.h"
#include "login.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showLogin();
    void showRegister();

private:
    Ui::MainWindow *ui;
    Login *loginPage;
    RegisterForm *registerPage;
};

#endif // MAINWINDOW_H
