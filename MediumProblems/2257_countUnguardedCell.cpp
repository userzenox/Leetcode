#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = empty, 1 = wall, 2 = guard, 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto &w : walls)
            grid[w[0]][w[1]] = 1; // mark wall
        for (auto &g : guards)
            grid[g[0]][g[1]] = 2; // mark guard

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        // For each guard, mark visible cells
        for (auto &g : guards) {
            int r0 = g[0], c0 = g[1];
            for (auto &d : dirs) {
                int r = r0 + d[0], c = c0 + d[1];
                while (r >= 0 && r < m && c >= 0 && c < n) {
                    if (grid[r][c] == 1 || grid[r][c] == 2)
                        break; // wall or another guard blocks vision
                    grid[r][c] = 3; // mark as guarded
                    r += d[0];
                    c += d[1];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    ans++;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Example 1
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};

    cout << "Example 1 Output: " << sol.countUnguarded(m, n, guards, walls) << "\n";

    // Example 2
    m = 3; n = 3;
    guards = {{1,1}};
    walls = {{0,1},{1,0},{2,1},{1,2}};
    cout << "Example 2 Output: " << sol.countUnguarded(m, n, guards, walls) << "\n";

    return 0;
}
