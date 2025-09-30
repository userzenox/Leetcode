#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        for (int num : nums) {
            if (num == max1 || num == max2 || num == max3) continue;
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }
        }
        return (max3 == LONG_MIN) ? max1 : max3;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 2, 1};
    vector<int> nums2 = {1, 2};
    vector<int> nums3 = {2, 2, 3, 1};
    
    cout << "Output 1: " << sol.thirdMax(nums1) << endl; // Output: 1
    cout << "Output 2: " << sol.thirdMax(nums2) << endl; // Output: 2
    cout << "Output 3: " << sol.thirdMax(nums3) << endl; // Output: 1

    return 0;
}
