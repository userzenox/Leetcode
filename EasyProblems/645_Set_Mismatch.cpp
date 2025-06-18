#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        int duplicate = -1, missing = -1;

        for (int num : nums) {
            count[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) duplicate = i;
            if (count[i] == 0) missing = i;
        }

        return {duplicate, missing};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;  // size of the array

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> ans = sol.findErrorNums(nums);

    // Output: duplicate missing
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}
