#include <iostream>
using namespace std;

int daysToFund(int start_balance, int daily_deposit) {
    const int vault_goal = 42500;
    int balance = start_balance;
    int days = 0;

    while (balance < vault_goal) {
        days++;
        balance += daily_deposit;

        cout << "Day " << days << ": deposited " << daily_deposit
             << ", balance now " << balance << endl;
    }

    return days;
}

int main() {
    int start_balance;
    int daily_deposit;

    cout << "Enter the starting Vault balance: ";
    cin >> start_balance;

    cout << "Enter the daily deposit amount: ";
    cin >> daily_deposit;

    cout << "--- Vault Savings Plan ---" << endl;

    int days = daysToFund(start_balance, daily_deposit);

    cout << "The Vault was funded in " << days << " days!" << endl;

    return 0;
}