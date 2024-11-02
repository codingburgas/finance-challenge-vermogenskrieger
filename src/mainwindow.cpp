#include "mainwindow.h"
#include "register.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Create the login and register pages
    Login *loginPage = new Login(this);
    RegisterForm *registerPage = new RegisterForm(this);

    // Add pages to the stacked widget
    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(registerPage);

    // Store pointers for easier access in showLogin and showRegister
    this->loginPage = loginPage;
    this->registerPage = registerPage;

    // Connect buttons to their respective slots
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::showLogin);
    connect(ui->registerButton, &QPushButton::clicked, this, &MainWindow::showRegister);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showLogin() {
    ui->stackedWidget->setCurrentWidget(loginPage); // Show login page
}

void MainWindow::showRegister() {
    ui->stackedWidget->setCurrentWidget(registerPage); // Show register page
}
