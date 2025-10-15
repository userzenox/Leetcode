#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int currrun = 1;
        int prevrun = 0;
        int k = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currrun++;
            } else {
                prevrun = currrun;
                currrun = 1;
            }

            k = max(k, currrun / 2);
            k = max(k, min(currrun, prevrun));
        }

        return k;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {1, 2, 3, 1, 2, 3, 4};
    int result = sol.maxIncreasingSubarrays(nums);
    
    cout << "Maximum increasing subarray length (k): " << result << endl;

    // You can test more cases below
    vector<int> nums2 = {5, 8, -2, -1};
    cout << "For {5, 8, -2, -1}, result = " << sol.maxIncreasingSubarrays(nums2) << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "For {1, 2, 3, 4, 5}, result = " << sol.maxIncreasingSubarrays(nums3) << endl;

    return 0;
}
