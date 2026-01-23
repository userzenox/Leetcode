#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;

        for (int x : nums) {
            auto it = upper_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }
        }

        int keep = lis.size();
        int removed = n - keep;

        // Each operation removes 2 elements
        return (removed + 1) / 2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.minimumPairRemoval(nums) << "\n";

    return 0;
}
