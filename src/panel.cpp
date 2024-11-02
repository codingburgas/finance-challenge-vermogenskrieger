#include "panel.h"
#include "ui_panel.h"

FinancePanel::FinancePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinancePanel) {
    ui->setupUi(this);
    initializeCategoryComboBox();

    // Connect slots to buttons
    connect(ui->addIncomeButton, &QPushButton::clicked, this, &FinancePanel::on_addIncomeButton_clicked);
    connect(ui->addExpenseButton, &QPushButton::clicked, this, &FinancePanel::on_addExpenseButton_clicked);
    connect(ui->setBudgetButton, &QPushButton::clicked, this, &FinancePanel::on_setBudgetButton_clicked);
    connect(ui->generateReportButton, &QPushButton::clicked, this, &FinancePanel::on_generateReportButton_clicked);

    // Initialize UI with default values
    updateTotalIncome();
    updateTotalExpense();
    updateNetIncome();
    updateUtilizationAndRemaining();
}

FinancePanel::~FinancePanel() {
    delete ui;
}

void FinancePanel::initializeCategoryComboBox() {
    ui->categoryComboBox->addItems({"Food", "Transport", "Utilities", "Entertainment", "Miscellaneous"});
}

void FinancePanel::on_addIncomeButton_clicked() {
    QString date = ui->incomeDateLineEdit->text().trimmed();
    QString category = ui->incomeCategoryLineEdit->text().trimmed();
    bool ok;
    double amount = ui->incomeAmountLineEdit->text().toDouble(&ok);

    if (date.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Date and category must not be empty.");
        return;
    }
    if (!ok || amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid positive amount.");
        return;
    }

    financeManager.addIncome(date.toStdString(), category.toStdString(), amount);
    updateTotalIncome();
    ui->incomeDateLineEdit->clear();
    ui->incomeCategoryLineEdit->clear();
    ui->incomeAmountLineEdit->clear();
}

void FinancePanel::on_addExpenseButton_clicked() {
    QString date = ui->expenseDateLineEdit->text().trimmed();
    QString category = ui->expenseCategoryLineEdit->text().trimmed();
    bool ok;
    double amount = ui->expenseAmountLineEdit->text().toDouble(&ok);

    if (date.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Date and category must not be empty.");
        return;
    }
    if (!ok || amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid positive amount.");
        return;
    }

    financeManager.addExpense(date.toStdString(), category.toStdString(), amount);
    updateTotalExpense();
    ui->expenseDateLineEdit->clear();
    ui->expenseCategoryLineEdit->clear();
    ui->expenseAmountLineEdit->clear();
}

void FinancePanel::on_setBudgetButton_clicked() {
    QString category = ui->budgetCategoryLineEdit->text().trimmed();
    bool ok;
    double amount = ui->budgetAmountLineEdit->text().toDouble(&ok);

    if (category.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Category must not be empty.");
        return;
    }
    if (!ok || amount <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid positive budget amount.");
        return;
    }

    financeManager.setBudget(category.toStdString(), amount);
    updateUtilizationAndRemaining();
}

void FinancePanel::on_generateReportButton_clicked() {
    updateNetIncome();
    updateCategorySummary();
}

void FinancePanel::updateTotalIncome() {
    double totalIncome = financeManager.getTotalIncome();
    ui->totalIncomeLabel->setText("Total Income: " + QString::number(totalIncome, 'f', 2));
}

void FinancePanel::updateTotalExpense() {
    double totalExpense = financeManager.getTotalExpense();
    ui->totalExpenseLabel->setText("Total Expense: " + QString::number(totalExpense, 'f', 2));
}

void FinancePanel::updateUtilizationAndRemaining() {
    QString category = ui->budgetCategoryLineEdit->text();
    double utilization = financeManager.getUtilization(category.toStdString());
    double remainingBudget = financeManager.getRemainingBudget(category.toStdString());

    ui->budgetUtilizationLabel->setText("Utilization: " + QString::number(utilization, 'f', 2) + "%");
    ui->remainingBudgetLabel->setText("Remaining Budget: " + QString::number(remainingBudget, 'f', 2));
}

void FinancePanel::updateNetIncome() {
    double netIncome = financeManager.getNetIncome();
    ui->netIncomeLabel->setText("Net Income: " + QString::number(netIncome, 'f', 2));
}

void FinancePanel::updateCategorySummary() {
    QString category = ui->categoryComboBox->currentText();
    auto summary = financeManager.getCategorySummary(category.toStdString());

    QString summaryText = "Income: " + QString::number(summary["Income"], 'f', 2) +
                          "\nExpense: " + QString::number(summary["Expense"], 'f', 2);
    ui->categorySummaryLabel->setText(summaryText);
}
