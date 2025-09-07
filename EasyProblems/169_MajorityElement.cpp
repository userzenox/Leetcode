#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                el = nums[i];
            }
            if (nums[i] == el) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        return el;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; // Example input
    int result = sol.majorityElement(nums);
    cout << "Majority element: " << result << endl; // Expected output: 2
    return 0;
}
