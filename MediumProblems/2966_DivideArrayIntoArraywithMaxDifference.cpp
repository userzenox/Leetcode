#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i += 3) {
            // Group of 3 consecutive elements
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];

            // Check max difference in group
            if (c - a > k) return {};  // Not valid

            result.push_back({a, b, c});
        }

        return result;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 3, 5, 4, 2, 6};
    int k = 2;

    Solution sol;
    vector<vector<int>> groups = sol.divideArray(nums, k);

    if (groups.empty()) {
        cout << "[]\n";
    } else {
        for (const auto& group : groups) {
            cout << "[ ";
            for (int num : group) cout << num << " ";
            cout << "]\n";
        }
    }

    return 0;
}
