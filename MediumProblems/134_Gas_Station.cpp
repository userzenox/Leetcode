#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int start = 0;
        int deficit = 0;

        for (int i = 0; i < gas.size(); i++) {
            balance += gas[i] - cost[i];

            if (balance < 0) {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        return (deficit + balance >= 0) ? start : -1;
    }
};

int main() {
    Solution sol;

    // Sample test case
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int startIndex = sol.canCompleteCircuit(gas, cost);

    if (startIndex != -1) {
        cout << "Start at station index: " << startIndex << endl;
    } else {
        cout << "It's not possible to complete the circuit." << endl;
    }

    return 0;
}
