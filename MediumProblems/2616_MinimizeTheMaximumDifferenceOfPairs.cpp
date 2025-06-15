#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        int i = 1;

        while (i < nums.size()) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2;  
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0, high = nums.back() - nums[0];
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFormPairs(nums, p, mid)) {
                ans = mid;
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {1, 3, 6, 19, 20};
    int p = 2;

    int result = sol.minimizeMax(nums, p);
    cout << "Minimum possible maximum difference: " << result << endl;

    return 0;
}
