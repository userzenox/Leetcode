#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {     
        int n = nums.size();
        if(k == 1) return 0;      // choosing 1 element always gives diff = 0

        sort(nums.begin(), nums.end());
        
        int mindiff = INT_MAX;
        for(int i = 0; i + k - 1 < n; i++){
            int diff = nums[i + k - 1] - nums[i];
            mindiff = min(mindiff, diff);
        }
        return mindiff;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.minimumDifference(nums, k) << endl;

    return 0;
}
