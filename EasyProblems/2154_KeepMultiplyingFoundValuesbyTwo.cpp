#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        while (numSet.count(original)) {
            original *= 2;
        }
        return original;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    int result = sol.findFinalValue(nums, original);
    cout << "Final value: " << result << endl;  // Expected output: 24

    return 0;
}
