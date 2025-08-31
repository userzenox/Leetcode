#include <iostream>
#include <vector>
#include <algorithm> // for std::max

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxi = max(maxi, count);
            } else {
                count = 0;
            }
        }
        return maxi;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    
    int maxConsecutive = solution.findMaxConsecutiveOnes(nums);
    
    cout << "Maximum consecutive ones: " << maxConsecutive << endl;
    
    return 0;
}
