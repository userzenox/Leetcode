#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        unordered_map<long long, long long> mleft, mright;

        // Count all numbers initially in right side
        for(long long num : nums) {
            mright[num]++;
        }

        long long count = 0;

        for(int i = 0; i < n; i++) {

            // Current element should no longer be on right side
            mright[nums[i]]--;

            long long target = 2LL * nums[i];

            // Count valid triplets
            if(mleft.count(target) && mright.count(target)) {
                count = (count + (mleft[target] * mright[target]) % MOD) % MOD;
            }

            // Now add current number to left side
            mleft[nums[i]]++;
        }

        return (int)count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 0};
    cout << s.specialTriplets(nums) << endl;
    return 0;
}
