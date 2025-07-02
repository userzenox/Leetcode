#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 4, 3, 2};

    Solution sol;
    int result = sol.arrayPairSum(nums);

    cout << "The maximum sum of min pairs is: " << result << endl;

    return 0;
}
