#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                result += count;
            } else {
                count = 0;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 0, 0, 2, 0, 0};
    cout << "Number of zero-filled subarrays: " << sol.zeroFilledSubarray(nums) << endl;
    return 0;
}
