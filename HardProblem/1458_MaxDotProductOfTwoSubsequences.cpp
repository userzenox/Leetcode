#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int m, n;
    int t[501][501];

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == m || j == n)
            return -1000000000; // force at least one pick

        if (t[i][j] != -1000000000)
            return t[i][j];

        int val = nums1[i] * nums2[j];

        // Option 1: take i,j and continue
        int takeij = val + solve(nums1, nums2, i + 1, j + 1);

        // Option 2: skip i
        int skipi = solve(nums1, nums2, i + 1, j);

        // Option 3: skip j
        int skipj = solve(nums1, nums2, i, j + 1);

        // Important: allow standalone val to avoid skipping all
        return t[i][j] = max({val, takeij, skipi, skipj});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        // initialize dp
        for (int i = 0; i < 501; i++)
            for (int j = 0; j < 501; j++)
                t[i][j] = -1000000000;

        int res = solve(nums1, nums2, 0, 0);

        // handle edge cases where best answer is single pair
        int best = -1000000000;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                best = max(best, nums1[i] * nums2[j]);

        return max(res, best);
    }
};

int main() {
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};

    Solution sol;
    cout << sol.maxDotProduct(nums1, nums2) << endl;
    return 0;
}
