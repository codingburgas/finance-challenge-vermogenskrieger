#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Задаване на стилове за основния интерфейс
    ui->statusLabel->clear();  // Изчистване на съобщенията при стартиране

    // Свързване на бутона за логин с обработката
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Функция за проверка на потребителско име и парола
bool MainWindow::verifyCredentials(const QString &username, const QString &password)
{
    // Пример за статично потребителско име и парола - замени с база данни, ако е нужно
    const QString correctUsername = "admin";
    const QString correctPassword = "password123";

    return (username == correctUsername && password == correctPassword);
}

// Обработка на кликване върху бутона за логин
void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (verifyCredentials(username, password)) {
        ui->statusLabel->setText("Успешен вход!");
        ui->statusLabel->setStyleSheet("QLabel { color : green; font-weight: bold; }");
        // Логика за пренасочване към друг прозорец или меню
    } else {
        ui->statusLabel->setText("Невалидно потребителско име или парола.");
        ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");
    }
}
