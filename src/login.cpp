#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login),
    failedAttempts(0)
{
    ui->setupUi(this);
    ui->statusLabel->clear();

    // Connect the forgot password button to its slot
    connect(ui->forgotButton, &QPushButton::clicked, this, &Login::on_forgotButton_clicked);
}

Login::~Login() {
    delete ui;
}

bool Login::verifyCredentials(const QString &username, const QString &password) {
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open user data file.");
        return false;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList credentials = line.split(" ");
        if (credentials.size() == 2) {
            QString storedUsername = credentials[0];
            QString storedPasswordHash = credentials[1];

            if (storedUsername == username && storedPasswordHash == hashedPassword) {
                correctUsersName = username;
                return true;
            }
        }
    }
    return false;
}

QString Login::exportCorrectUsersName() const {
    qDebug() << "Successfully exported" << correctUsersName;
    return correctUsersName;
}

void Login::on_loginButton_clicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    ui->statusLabel->setText("Logging in..."); // Feedback message
    ui->statusLabel->setStyleSheet("QLabel { color : blue; font-weight: bold; }");

    if (verifyCredentials(username, password)) {
        ui->statusLabel->setText("Login successful!");
        ui->statusLabel->setStyleSheet("QLabel { color : green; font-weight: bold; }");

        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();

        emit loginSuccessful();  // Emit the login successful signal
    } else {
        ui->statusLabel->setText("Invalid username or password.");
        ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");
        failedAttempts++;
        if (failedAttempts >= 3) {
            QMessageBox::warning(this, "Login Failed", "Please check your credentials.");
            failedAttempts = 0;
        }
    }
}

void Login::on_forgotButton_clicked() {
    emit showRegisterRequested(); // Emit signal to request the register page
}
