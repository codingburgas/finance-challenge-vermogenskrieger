#include "financemanager.h"

// Income Management
void FinanceManager::addIncome(const std::string& date, const std::string& category, double amount) {
    incomes.push_back({date, category, amount});
}

double FinanceManager::getTotalIncome() const {
    double totalIncome = 0;
    for (const auto& income : incomes) {
        totalIncome += income.amount;
    }
    return totalIncome;
}

double FinanceManager::getMonthlyIncome(const std::string& month) const {
    double monthlyIncome = 0;
    for (const auto& income : incomes) {
        if (income.date.substr(0, 7) == month) {
            monthlyIncome += income.amount;
        }
    }
    return monthlyIncome;
}

// Expense Management
void FinanceManager::addExpense(const std::string& date, const std::string& category, double amount) {
    expenses.push_back({date, category, amount});
}

double FinanceManager::getTotalExpense() const {
    double totalExpense = 0;
    for (const auto& expense : expenses) {
        totalExpense += expense.amount;
    }
    return totalExpense;
}

double FinanceManager::getMonthlyExpense(const std::string& month) const {
    double monthlyExpense = 0;
    for (const auto& expense : expenses) {
        if (expense.date.substr(0, 7) == month) {
            monthlyExpense += expense.amount;
        }
    }
    return monthlyExpense;
}

// Budget Planning
void FinanceManager::setBudget(const std::string& category, double amount) {
    budget[category] = amount;
}

double FinanceManager::getUtilization(const std::string& category) const {
    double categoryExpense = 0;
    for (const auto& expense : expenses) {
        if (expense.category == category) {
            categoryExpense += expense.amount;
        }
    }
    if (budget.count(category) == 0) return 0; // No budget set for this category
    return (categoryExpense / budget.at(category)) * 100;
}

double FinanceManager::getRemainingBudget(const std::string& category) const {
    double categoryExpense = 0;
    for (const auto& expense : expenses) {
        if (expense.category == category) {
            categoryExpense += expense.amount;
        }
    }
    if (budget.count(category) == 0) return 0; // No budget set for this category
    return budget.at(category) - categoryExpense;
}

// Report Generation
double FinanceManager::getNetIncome() const {
    return getTotalIncome() - getTotalExpense();
}

std::map<std::string, double> FinanceManager::getCategorySummary(const std::string& category) const {
    double incomeSum = 0, expenseSum = 0;
    for (const auto& income : incomes) {
        if (income.category == category) incomeSum += income.amount;
    }
    for (const auto& expense : expenses) {
        if (expense.category == category) expenseSum += expense.amount;
    }
    return {{"Income", incomeSum}, {"Expense", expenseSum}};
}

// Expense Analysis
std::map<std::string, double> FinanceManager::getCategoryPercentage() const {
    double totalExpense = getTotalExpense();
    std::map<std::string, double> percentage;
    for (const auto& expense : expenses) {
        percentage[expense.category] += expense.amount;
    }
    for (auto& it : percentage) {
        it.second = (totalExpense > 0) ? (it.second / totalExpense) * 100 : 0; // Avoid division by zero
    }
    return percentage;
}

double FinanceManager::getAverageMonthlyExpense(const std::string& category, int monthsTracked) const {
    double categoryExpense = 0;
    for (const auto& expense : expenses) {
        if (expense.category == category) {
            categoryExpense += expense.amount;
        }
    }
    return (monthsTracked > 0) ? categoryExpense / monthsTracked : 0;
}
