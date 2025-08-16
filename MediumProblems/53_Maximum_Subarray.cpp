#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0; 
        int maxs = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxs = max(maxs, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxs;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.maxSubArray(nums);
    
    cout << "Maximum subarray sum = " << result << endl;
    return 0;
}
