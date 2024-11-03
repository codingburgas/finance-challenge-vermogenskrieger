#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <string>
#include <vector>
#include <map>

struct Expense {
    std::string category;
    double amount; // Use double for the amount
};

class FinanceManager {
public:
    void addIncome(const std::string& date, const std::string& category, double amount);
    double getTotalIncome() const;
    double getMonthlyIncome(const std::string& month) const;

    void addExpense(const std::string& date, const std::string& category, double amount);
    double getTotalExpense() const;
    double getMonthlyExpense(const std::string& month) const;

    void setBudget(const std::string& category, double amount);
    double getUtilization(const std::string& category) const;
    double getRemainingBudget(const std::string& category) const;

    double getNetIncome() const;
    std::map<std::string, double> getCategorySummary(const std::string& category) const;
    std::map<std::string, double> getCategoryPercentage() const;
    double getAverageMonthlyExpense(const std::string& category, int monthsTracked) const;

    std::vector<Expense> getExpenses() const {
        // Sample implementation
        return {
            {"Food", 100.0},
            {"Transport", 50.0},
            {"Entertainment", 150.0}
        };
    }

private:
    struct Transaction {
        std::string date;
        std::string category;
        double amount;
    };

    std::vector<Transaction> incomes;
    std::vector<Transaction> expenses;
    std::map<std::string, double> budget;
};

#endif // FINANCEMANAGER_H
