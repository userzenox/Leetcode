#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        // Count how many 1s are already in the array
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                count++;
        }

        // If there is at least one 1
        if (count != 0)
            return n - count;

        int minoperation = INT_MAX;

        // Find smallest subarray with GCD == 1
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    minoperation = min(minoperation, j - i);
                    break;
                }
            }
        }

        // If no subarray with gcd = 1 exists, return -1
        if (minoperation == INT_MAX)
            return -1;

        // Total operations = steps to get one 1 + (n - 1)
        return minoperation + n - 1;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {2, 6, 3, 4};
    cout << "Minimum operations: " << sol.minOperations(nums1) << endl;

    // Example 2
    vector<int> nums2 = {2, 10, 6, 14};
    cout << "Minimum operations: " << sol.minOperations(nums2) << endl;

    // Example 3 (already has 1s)
    vector<int> nums3 = {1, 1, 2, 3};
    cout << "Minimum operations: " << sol.minOperations(nums3) << endl;

    return 0;
}
