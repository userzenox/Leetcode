#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numRows = strs.size();
        int numCols = strs[0].size();
        int deletions = 0;

        // iterate over each column
        for (int c = 0; c < numCols; ++c) {
            // check if column c is sorted from top to bottom
            for (int r = 1; r < numRows; ++r) {
                if (strs[r][c] < strs[r - 1][c]) {
                    ++deletions;
                    break;          // this column already bad, go to next column
                }
            }
        }
        return deletions;
    }
};

int main() {
    // example input
    vector<string> strs = {"cba", "daf", "ghi"};

    Solution sol;
    int ans = sol.minDeletionSize(strs);

    cout << "Minimum columns to delete = " << ans << endl;
    return 0;
}
