#include <bits/stdc++.h>
using namespace std;

class Bank {
public:
    map<int, long long> m;  // maps account number → balance

    // Constructor: initializes all account balances
    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); ++i) {
            m[i + 1] = balance[i];   // account numbers start from 1
        }
    }

    // Transfer money from account1 → account2
    bool transfer(int account1, int account2, long long money) {
        // Check if both accounts exist
        if (m.find(account1) == m.end() || m.find(account2) == m.end())
            return false;

        // Check if sender has enough balance
        if (m[account1] >= money) {
            m[account1] -= money;
            m[account2] += money;
            return true;
        }
        return false;
    }

    // Deposit money into an account
    bool deposit(int account, long long money) {
        if (m.find(account) == m.end()) return false; // invalid account
        m[account] += money;
        return true;
    }

    // Withdraw money from an account
    bool withdraw(int account, long long money) {
        if (m.find(account) == m.end()) return false; // invalid account
        if (m[account] >= money) {
            m[account] -= money;
            return true;
        }
        return false;
    }
};

// Example usage
int main() {
    vector<long long> balance = {1000, 2000, 3000};   // initial balances
    Bank* obj = new Bank(balance);  // creating a Bank object

    cout << boolalpha; // print true/false instead of 1/0

    cout << "Transfer 500 from acc1 → acc2: " 
         << obj->transfer(1, 2, 500) << endl;

    cout << "Deposit 1000 into acc3: " 
         << obj->deposit(3, 1000) << endl;

    cout << "Withdraw 300 from acc2: " 
         << obj->withdraw(2, 300) << endl;

    cout << "Withdraw 5000 from acc1 (should fail): " 
         << obj->withdraw(1, 5000) << endl;

    return 0;
}
