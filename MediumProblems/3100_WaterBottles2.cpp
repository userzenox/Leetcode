#include <iostream>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int totalDrunk = numBottles;
    int empties = numBottles;
    while (empties >= numExchange) {
        int newBottles = empties / numExchange;
        totalDrunk += newBottles;
        empties = empties % numExchange + newBottles;
    }
    return totalDrunk;
}

int main() {
    int numBottles, numExchange;
    cin >> numBottles >> numExchange;
    cout << numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}
