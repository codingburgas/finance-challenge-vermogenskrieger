#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QMessageBox>
#include "financemanager.h"

namespace Ui {
class FinancePanel;
}

class FinancePanel : public QWidget {
    Q_OBJECT

public:
    explicit FinancePanel(QWidget *parent = nullptr);
    ~FinancePanel();

private slots:
    void on_addIncomeButton_clicked();
    void on_addExpenseButton_clicked();
    void on_setBudgetButton_clicked();
    void on_generateReportButton_clicked();

private:
    void initializeCategoryComboBox();
    void updateTotalIncome();
    void updateTotalExpense();
    void updateUtilizationAndRemaining();
    void updateNetIncome();
    void updateCategorySummary();

    Ui::FinancePanel *ui;
    FinanceManager financeManager; // Add your finance manager instance here
};

#endif // PANEL_H

