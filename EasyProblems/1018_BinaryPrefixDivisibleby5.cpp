#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0;

        for (int i = 0; i < nums.size(); i++) {
            x = (x * 2 + nums[i]) % 5;   // keep remainder only
            ans.push_back(x == 0);       // divisible by 5 if remainder is 0
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1};

    Solution sol;
    vector<bool> result = sol.prefixesDivBy5(nums);

    // Print output
    for (bool b : result) {
        cout << (b ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
