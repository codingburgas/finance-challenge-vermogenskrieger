#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);

    RegisterForm *registerPage = new RegisterForm(this);
    Login *loginPage = new Login(this);

    stackedWidget->addWidget(registerPage);
    stackedWidget->addWidget(loginPage);

    setCentralWidget(stackedWidget);

    connect(registerPage, &RegisterForm::registrationSuccessful, this, &MainWindow::showLogin);
    connect(registerPage->buttonToLogin, &QPushButton::clicked, this, &MainWindow::showLogin);
    connect(loginPage->buttonToRegister, &QPushButton::clicked, this, &MainWindow::showRegister);
}

MainWindow::~MainWindow() {}

void MainWindow::showRegister() {
    stackedWidget->setCurrentWidget(stackedWidget->widget(0)); // Show register page
}

void MainWindow::showLogin() {
    stackedWidget->setCurrentWidget(stackedWidget->widget(1)); // Show login page
}
