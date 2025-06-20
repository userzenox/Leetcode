#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 1;
        int min_value = nums[0]; // Start of the first group

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - min_value > k) {
                count++;
                min_value = nums[i]; // Reset min_value for the new group
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 6, 1, 2, 5};
    int k = 2;

    int result = sol.partitionArray(nums, k);
    cout << "Minimum number of subsequences: " << result << endl;

    return 0;
}
