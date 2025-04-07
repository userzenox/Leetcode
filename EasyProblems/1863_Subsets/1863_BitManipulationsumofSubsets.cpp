#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        int sum = 0;

        for (int i = 0; i < subsets; i++) {
            int xorVal = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    xorVal ^= nums[j];
                }
            }
            sum += xorVal;
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    int result = sol.subsetXORSum(nums);
    cout << "Sum of XOR of all subsets: " << result << endl;

    return 0;
}
