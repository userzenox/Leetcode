#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> result;

        for (int i = 0; i < n; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m - 1);
        }
        for (int j = 0; j < m; ++j) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n - 1, j);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }

    void dfs(const vector<vector<int>>& heights, vector<vector<int>>& visited, int x, int y) {
        int n = heights.size(), m = heights[0].size();
        visited[x][y] = 1;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            if (heights[nx][ny] < heights[x][y]) continue;
            dfs(heights, visited, nx, ny);
        }
    }
};

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    Solution sol;
    vector<vector<int>> result = sol.pacificAtlantic(heights);

    cout << "Cells where water can flow to both Pacific and Atlantic:" << endl;
    for (const auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]" << endl;
    }
    return 0;
}
