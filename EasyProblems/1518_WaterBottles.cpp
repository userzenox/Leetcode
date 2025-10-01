#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            int newBottles = empty / numExchange;
            total += newBottles;
            empty = (empty % numExchange) + newBottles;
        }
        return total;
    }
};

int main() {
    int numBottles, numExchange;
    cout << "Enter number of bottles: ";
    cin >> numBottles;
    cout << "Enter number of bottles required for exchange: ";
    cin >> numExchange;
    
    Solution sol;
    int result = sol.numWaterBottles(numBottles, numExchange);
    cout << "Maximum water bottles drunk: " << result << endl;
    return 0;
}
