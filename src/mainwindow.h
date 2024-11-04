#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "login.h"
#include "register.h"
#include "panel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showLogin();
    void showRegister();
    void showPanel();
    void onLoginSuccessful(); // Slot to handle successful login

private:
    Ui::MainWindow *ui;
    Login *loginPage;
    RegisterForm *registerPage;
    FinancePanel *panel; // Your main content page after login
};
#endif // MAINWINDOW_H
