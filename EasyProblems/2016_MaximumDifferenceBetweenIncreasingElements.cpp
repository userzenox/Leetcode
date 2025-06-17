#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0];
        int max_diff = -1;

        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > min_val) {
                max_diff = max(max_diff, nums[i] - min_val);
            } else {
                min_val = nums[i];
            }
        }

        return max_diff;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7, 1, 5, 4};  // You can change input here
    int result = sol.maximumDifference(nums);
    cout << "Maximum Difference: " << result << endl;
    return 0;
}
