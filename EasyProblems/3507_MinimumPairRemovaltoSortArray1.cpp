#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {   
        int index = -1;
        int operations = 0;

        while (!is_sorted(nums.begin(), nums.end())) {
            int minsum = INT_MAX;

            for (int i = 0; i < (int)nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minsum) {
                    minsum = sum;
                    index = i;
                }
            }

            nums[index] = minsum;
            nums.erase(nums.begin() + index + 1);
            operations++;
        }

        return operations; 
    }
};

int main() {
    vector<int> nums = {5, 2, 3, 1};

    Solution sol;
    int result = sol.minimumPairRemoval(nums);

    cout << result << endl;   // Expected output: 2

    return 0;
}
