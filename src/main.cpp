#include "mainwindow.h"

#include "FinanceManager.h"
#include <iostream>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    \
        FinanceManager fm;

        // Adding incomes
        fm.addIncome("2024-10-01", "Salary", 2000.00);
        fm.addIncome("2024-10-15", "Investments", 500.00);

        // Adding expenses
        fm.addExpense("2024-10-05", "Food", 200.00);
        fm.addExpense("2024-10-10", "Rent", 800.00);
        fm.addExpense("2024-10-20", "Entertainment", 100.00);

        // Setting budget
        fm.setBudget("Food", 300.00);
        fm.setBudget("Rent", 800.00);

        // Displaying total income and expense
        std::cout << "Total Income: " << fm.getTotalIncome() << std::endl;
        std::cout << "Total Expense: " << fm.getTotalExpense() << std::endl;

        // Budget utilization
        std::cout << "Food Budget Utilization: " << fm.getUtilization("Food") << "%" << std::endl;

        // Expense analysis
        auto categoryPercentage = fm.getCategoryPercentage();
        for (const auto& [category, percent] : categoryPercentage) {
            std::cout << "Category: " << category << " - " << percent << "%" << std::endl;
        }

        return 0;

}
