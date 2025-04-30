#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            int s = nums[i];
            int count = 0;
            while (s != 0) {
                count++;
                s = s / 10;
            }
            if (count % 2 == 0) {
                n++;
            }
        }
        return n;

        // Alternative constant-time method (uncomment to use):
        // int result = 0;
        // for (int num : nums) {
        //     if ((num >= 10 && num <= 99) || 
        //         (num >= 1000 && num <= 9999) || 
        //         (num == 100000)) {
        //         result++;
        //     }
        // }
        // return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12, 345, 2, 6, 7896}; // Input vector

    int result = sol.findNumbers(nums);
    cout << "Number of integers with even number of digits: " << result << endl;

    return 0;
}
