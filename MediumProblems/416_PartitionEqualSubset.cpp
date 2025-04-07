#include <iostream>
#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int subsetSum = sum / 2;
        std::vector<bool> dp(subsetSum + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = subsetSum; j >= num; --j) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }

        return dp[subsetSum];
    }
};

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    Solution solution;
    bool result = solution.canPartition(nums);

    if (result) {
        std::cout << "The array can be partitioned into two subsets with equal sum.\n";
    } else {
        std::cout << "The array cannot be partitioned into two subsets with equal sum.\n";
    }

    return 0;
}
