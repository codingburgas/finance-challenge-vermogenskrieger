#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initialize login and register pages
    loginPage = new Login(this);
    registerPage = new RegisterForm(this);

    // Add pages to the stacked widget
    ui->stackedWidget->addWidget(registerPage);  // Show register page first
    ui->stackedWidget->addWidget(loginPage);

    // Show register page by default
    ui->stackedWidget->setCurrentWidget(registerPage);

    // Connect signals for navigation
    connect(loginPage, &Login::showRegisterRequested, this, &MainWindow::showRegister);
    connect(registerPage, &RegisterForm::registrationSuccessful, this, &MainWindow::showLogin);

    // Connect the login link from register page to the showLogin function
    connect(registerPage, &RegisterForm::loginRequested, this, &MainWindow::showLoginFromRegister);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showLogin() {
    ui->stackedWidget->setCurrentWidget(loginPage); // Switch to login page
}

void MainWindow::showRegister() {
    ui->stackedWidget->setCurrentWidget(registerPage); // Switch to register page
}

void MainWindow::showLoginFromRegister() {
    ui->stackedWidget->setCurrentWidget(loginPage); // Switch to login page
}
