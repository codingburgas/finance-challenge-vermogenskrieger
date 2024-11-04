#include "panel.h"
#include "ui_panel.h"
#include "filecontrol.h"
#include <QDebug>
#include <QString>

FinancePanel::FinancePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinancePanel) {
    ui->setupUi(this);
}

FinancePanel::~FinancePanel() {
    delete ui;
}

QString FinancePanel::getFile(){
    filecontrol fl;

    QString file = fl.readFile("temp.txt");

    while(file.isEmpty()){
        file = fl.readFile("temp.txt");
    }
    qDebug() << "the file is "<< file;

    return file;
}

// Slot for adding income
void FinancePanel::on_addIncomeButton_clicked() {
    QString date = ui->incomeDateLineEdit->text().trimmed();
    QString category = ui->incomeCategoryLineEdit->text().trimmed();
    bool ok;
    double amount = ui->incomeAmountLineEdit->text().toDouble(&ok);

    // Debug output to check values
    qDebug() << "Add Income - Date:" << date << "Category:" << category << "Amount:" << amount;

    // Input validation
    if (date.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Date must not be empty.");
        return;
    }
    if (category.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Category must not be empty.");
        return;
    }
    if (!ok || amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid positive amount.");
        return;
    }

    // Add income to the finance manager
    financeManager.addIncome(date.toStdString(), category.toStdString(), amount);

    // Update UI and clear inputs
    updateTotalIncome();
    ui->incomeDateLineEdit->clear();
    ui->incomeCategoryLineEdit->clear();
    ui->incomeAmountLineEdit->clear();

    getFile();
}

// Slot for adding expense
void FinancePanel::on_addExpenseButton_clicked() {
    QString date = ui->expenseDateLineEdit->text().trimmed();
    QString category = ui->expenseCategoryLineEdit->text().trimmed();
    bool ok;
    double amount = ui->expenseAmountLineEdit->text().toDouble(&ok);

    // Debug output to check values
    qDebug() << "Add Expense - Date:" << date << "Category:" << category << "Amount:" << amount;

    // Input validation
    if (date.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Date must not be empty.");
        return;
    }
    if (category.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Category must not be empty.");
        return;
    }
    if (!ok || amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid positive amount.");
        return;
    }

    financeManager.addExpense(date.toStdString(), category.toStdString(), amount);
    updateTotalExpense();

    // Clear the input fields
    ui->expenseDateLineEdit->clear();
    ui->expenseCategoryLineEdit->clear();
    ui->expenseAmountLineEdit->clear();
}

// Slot for setting the budget
void FinancePanel::on_setBudgetButton_clicked() {
    QString category = ui->budgetCategoryLineEdit->text().trimmed();
    bool ok;
    double amount = ui->budgetAmountLineEdit->text().toDouble(&ok);

    // Debug output to check values
    qDebug() << "Set Budget - Category:" << category << "Amount:" << amount;

    // Input validation
    if (category.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Category must not be empty.");
        return;
    }
    if (!ok || amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid positive budget.");
        return;
    }

    financeManager.setBudget(category.toStdString(), amount);
    updateUtilizationAndRemaining();
}

// Slot for generating a report
void FinancePanel::on_generateReportButton_clicked() {
    updateNetIncome();
    updateCategorySummary();
}

// Update total income displayed in the UI
void FinancePanel::updateTotalIncome() {
    double totalIncome = financeManager.getTotalIncome();
    ui->totalIncomeLabel->setText("Total Income: " + QString::number(totalIncome));
}

// Update total expense displayed in the UI
void FinancePanel::updateTotalExpense() {
    double totalExpense = financeManager.getTotalExpense();
    ui->totalExpenseLabel->setText("Total Expense: " + QString::number(totalExpense));
}

// Update budget utilization and remaining amount
void FinancePanel::updateUtilizationAndRemaining() {
    QString category = ui->budgetCategoryLineEdit->text().trimmed();
    double utilization = financeManager.getUtilization(category.toStdString());
    double remainingBudget = financeManager.getRemainingBudget(category.toStdString());

    // Debug output to check budget values
    qDebug() << "Budget Utilization - Category:" << category << "Utilization:" << utilization << "%" << "Remaining Budget:" << remainingBudget;

    ui->budgetUtilizationLabel->setText("Utilization: " + QString::number(utilization) + "%");
    ui->remainingBudgetLabel->setText("Remaining Budget: " + QString::number(remainingBudget));
}

// Update net income displayed in the UI
void FinancePanel::updateNetIncome() {
    double netIncome = financeManager.getNetIncome();
    ui->netIncomeLabel->setText("Net Income: " + QString::number(netIncome));

    // Debug output to check net income value
    qDebug() << "Net Income:" << netIncome;
}

// Update category summary displayed in the UI
void FinancePanel::updateCategorySummary() {
    QString category = ui->categoryComboBox->currentText();
    auto summary = financeManager.getCategorySummary(category.toStdString());

    QString summaryText = "Income: " + QString::number(summary["Income"]) +
                          "\nExpense: " + QString::number(summary["Expense"]);
    ui->categorySummaryLabel->setText(summaryText);

    // Debug output to check category summary
    qDebug() << "Category Summary - Category:" << category << summaryText;
}



