#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "register.h" // Include RegisterForm header
#include "login.h"    // Include Login header

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showRegister();
    void showLogin();

private:
    QStackedWidget *stackedWidget;
};

#endif // MAINWINDOW_H
