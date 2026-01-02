#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;

        for (int x : nums) {
            if (seen.count(x)) {   // seen before -> this is the answer
                return x;
            }
            seen.insert(x);
        }

        return -1; // should never reach here for valid input
    }
};

int main() {
    int n;
    cin >> n;               // size of nums (always even, 2*N)
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];     // elements (0 <= nums[i] < 10000)
    }

    Solution sol;
    cout << sol.repeatedNTimes(nums) << "\n";

    return 0;
}
