#include "panel.h"
#include "ui_panel.h"

FinancePanel::FinancePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinancePanel) { // Updated to match the class name
    ui->setupUi(this);
}

FinancePanel::~FinancePanel() {
    delete ui;
}

// Slot for adding income
void FinancePanel::on_addIncomeButton_clicked() {
    std::string date = ui->incomeDateLineEdit->text().toStdString();
    std::string category = ui->incomeCategoryLineEdit->text().toStdString();
    double amount = ui->incomeAmountLineEdit->text().toDouble();

    financeManager.addIncome(date, category, amount);
    updateTotalIncome();

    // Clear the input fields
    ui->incomeDateLineEdit->clear();
    ui->incomeCategoryLineEdit->clear();
    ui->incomeAmountLineEdit->clear();
}

// Slot for adding expense
void FinancePanel::on_addExpenseButton_clicked() {
    std::string date = ui->expenseDateLineEdit->text().toStdString();
    std::string category = ui->expenseCategoryLineEdit->text().toStdString();
    double amount = ui->expenseAmountLineEdit->text().toDouble();

    financeManager.addExpense(date, category, amount);
    updateTotalExpense();

    // Clear the input fields
    ui->expenseDateLineEdit->clear();
    ui->expenseCategoryLineEdit->clear();
    ui->expenseAmountLineEdit->clear();
}

// Slot for setting the budget
void FinancePanel::on_setBudgetButton_clicked() {
    std::string category = ui->budgetCategoryLineEdit->text().toStdString();
    double amount = ui->budgetAmountLineEdit->text().toDouble();

    financeManager.setBudget(category, amount);
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
    std::string category = ui->budgetCategoryLineEdit->text().toStdString();
    double utilization = financeManager.getUtilization(category);
    double remainingBudget = financeManager.getRemainingBudget(category);

    ui->budgetUtilizationLabel->setText("Utilization: " + QString::number(utilization) + "%");
    ui->remainingBudgetLabel->setText("Remaining Budget: " + QString::number(remainingBudget));
}

// Update net income displayed in the UI
void FinancePanel::updateNetIncome() {
    double netIncome = financeManager.getNetIncome();
    ui->netIncomeLabel->setText("Net Income: " + QString::number(netIncome));
}

// Update category summary displayed in the UI
void FinancePanel::updateCategorySummary() {
    std::string category = ui->categoryComboBox->currentText().toStdString();
    auto summary = financeManager.getCategorySummary(category);

    QString summaryText = "Income: " + QString::number(summary["Income"]) +
                          "\nExpense: " + QString::number(summary["Expense"]);
    ui->categorySummaryLabel->setText(summaryText);
}
