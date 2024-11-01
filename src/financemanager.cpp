#include "financemanager.h"


//Income Management
void FinanceManager::addIncome(const std::string& date, const std::string& category, double amount) {
    incomes.push_back({date, category, amount});
}

double FinanceManager::getTotalIncome() const {
    double totalIncome = 0;
    for (size_t i = 0; i < incomes.size(); ++i) {
        totalIncome += incomes[i].amount;
    }
    return totalIncome;
}

double FinanceManager::getMonthlyIncome(const std::string& month) const {
    double monthlyIncome = 0;
    for (size_t i = 0; i < incomes.size(); ++i) {
        if (incomes[i].date.substr(0, 7) == month) {
            monthlyIncome += incomes[i].amount;
        }
    }
    return monthlyIncome;
}

//Expense Management
void FinanceManager::addExpense(const std::string& date, const std::string& category, double amount) {
    expenses.push_back({date, category, amount});
}

double FinanceManager::getTotalExpense() const {
    double totalExpense = 0;
    for (size_t i = 0; i < expenses.size(); ++i) {
        totalExpense += expenses[i].amount;
    }
    return totalExpense;
}

double FinanceManager::getMonthlyExpense(const std::string& month) const {
    double monthlyExpense = 0;
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].date.substr(0, 7) == month) {
            monthlyExpense += expenses[i].amount;
        }
    }
    return monthlyExpense;
}

//Budget Planning
void FinanceManager::setBudget(const std::string& category, double amount) {
    budget[category] = amount;
}

double FinanceManager::getUtilization(const std::string& category) const {
    double categoryExpense = 0;
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].category == category) {
            categoryExpense += expenses[i].amount;
        }
    }
    if (budget.count(category) == 0) return 0; // No budget set for this category
    return (categoryExpense / budget.at(category)) * 100;
}

double FinanceManager::getRemainingBudget(const std::string& category) const {
    double categoryExpense = 0;
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].category == category) {
            categoryExpense += expenses[i].amount;
        }
    }
    if (budget.count(category) == 0) return 0; // No budget set for this category
    return budget.at(category) - categoryExpense;
}

//Report Generation
double FinanceManager::getNetIncome() const {
    return getTotalIncome() - getTotalExpense();
}

std::map<std::string, double> FinanceManager::getCategorySummary(const std::string& category) const {
    double incomeSum = 0, expenseSum = 0;
    for (size_t i = 0; i < incomes.size(); ++i) {
        if (incomes[i].category == category) incomeSum += incomes[i].amount;
    }
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].category == category) expenseSum += expenses[i].amount;
    }
    return {{"Income", incomeSum}, {"Expense", expenseSum}};
}

//Expense Analysis
std::map<std::string, double> FinanceManager::getCategoryPercentage() const {
    double totalExpense = getTotalExpense();
    std::map<std::string, double> percentage;
    for (size_t i = 0; i < expenses.size(); ++i) {
        percentage[expenses[i].category] += expenses[i].amount;
    }
    for (auto it = percentage.begin(); it != percentage.end(); ++it) {
        it->second = (it->second / totalExpense) * 100;
    }
    return percentage;
}

double FinanceManager::getAverageMonthlyExpense(const std::string& category, int monthsTracked) const {
    double categoryExpense = 0;
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].category == category) {
            categoryExpense += expenses[i].amount;
        }
    }
    return monthsTracked > 0 ? categoryExpense / monthsTracked : 0;
}
