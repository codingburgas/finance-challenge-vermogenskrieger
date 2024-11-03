#include "mainwindow.h"
#include "filecontrol.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initialize login and register pages
    loginPage = new Login(this);
    registerPage = new RegisterForm(this);

    // Initialize your main content page here (replace with actual content)
    panel = new FinancePanel(this);
    panel->setWindowTitle("Main Content"); // Just an example title

    // Add pages to the stacked widget
    ui->stackedWidget->addWidget(registerPage);  // Show register page first
    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(panel); // Add main content page to stacked widget

    // Show register page by default
    ui->stackedWidget->setCurrentWidget(registerPage);

    // Connect signals for navigation
    connect(loginPage, &Login::showRegisterRequested, this, &MainWindow::showRegister);
    connect(registerPage, &RegisterForm::registrationSuccessful, this, &MainWindow::showLogin);
    connect(registerPage, &RegisterForm::loginRequested, this, &MainWindow::showPanel);

    // Connect the login successful signal
    connect(loginPage, &Login::loginSuccessful, this, &MainWindow::onLoginSuccessful);
}

MainWindow::~MainWindow() {
    delete ui;
    filecontrol fl;
    fl.eraseFile("temp.txt");
}

void MainWindow::showLogin() {
    ui->stackedWidget->setCurrentWidget(loginPage); // Switch to login page
}

void MainWindow::showRegister() {
    ui->stackedWidget->setCurrentWidget(registerPage); // Switch to register page
}

void MainWindow::showPanel() {
    ui->stackedWidget->setCurrentWidget(loginPage); // Switch to login page
}

void MainWindow::onLoginSuccessful() {
    ui->stackedWidget->setCurrentWidget(panel); // Switch to the main content page
}
