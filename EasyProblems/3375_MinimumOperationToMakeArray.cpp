#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minOperations(vector<int>& nums, int k) {
    // Check if it's possible
    for (int num : nums) {
        if (num < k) return -1;
    }

    // Extract all values greater than k
    vector<int> valuesAboveK;
    for (int num : nums) {
        if (num > k) {
            valuesAboveK.push_back(num);
        }
    }

    if (valuesAboveK.empty()) return 0;

    // Sort in descending order
    sort(valuesAboveK.begin(), valuesAboveK.end(), greater<int>());

    // Count unique elements manually
    int operations = 1;  // At least one value > k exists
    for (int i = 1; i < valuesAboveK.size(); ++i) {
        if (valuesAboveK[i] != valuesAboveK[i - 1]) {
            operations++;
        }
    }

    return operations;
}

int main() {
    vector<int> nums = {10, 8, 10, 8};
    int k = 8;

    int result = minOperations(nums, k);
    cout << "Minimum operations: " << result << endl;

    return 0;
}
