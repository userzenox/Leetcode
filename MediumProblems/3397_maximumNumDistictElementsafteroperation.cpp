#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int prev = INT_MIN;

        for(int i = 0; i < n; i++) {
            int minVal = nums[i] - k;
            // Assign the smallest possible value that is greater than previous assigned
            if(prev < minVal) {
                prev = minVal;
                count++;
            } 
            else if(prev < nums[i] + k) {
                prev = prev + 1;
                count++;
            } 
            // else, cannot assign within range, so skip
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 3, 3, 4};
    int k1 = 2;
    cout << "Output 1: " << sol.maxDistinctElements(nums1, k1) << endl;

    vector<int> nums2 = {4, 4, 4, 4};
    int k2 = 1;
    cout << "Output 2: " << sol.maxDistinctElements(nums2, k2) << endl;

    vector<int> nums3 = {1, 5, 8};
    int k3 = 2;
    cout << "Output 3: " << sol.maxDistinctElements(nums3, k3) << endl;

    return 0;
}
