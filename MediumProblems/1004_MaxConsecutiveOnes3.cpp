#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeros = 0;
        int max_len = 0;

        for (int right = 0; right < (int)nums.size(); ++right) {
            if (nums[right] == 0) {
                zeros++;
            }
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int k = 2;

    int result = sol.longestOnes(nums, k);
    cout << "Longest consecutive ones with at most " << k << " zero flips: " << result << endl;

    return 0;
}
