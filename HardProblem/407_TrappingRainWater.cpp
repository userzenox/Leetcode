#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.empty() || heightMap[0].empty()) return 0;
    int n = heightMap.size();
    int m = heightMap[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

    // Push all boundary cells to the min-heap
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                q.push({heightMap[i][j], i, j});
                vis[i][j] = 1;
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int ans = 0;

    // BFS using min-heap
    while (!q.empty()) {
        int h = q.top()[0];
        int x = q.top()[1];
        int y = q.top()[2];
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            // Check bounds and if cell not visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                // Water trapped calculation
                ans += max(h - heightMap[nx][ny], 0);
                q.push({max(h, heightMap[nx][ny]), nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };
    cout << trapRainWater(heightMap) << endl;  // Output should be 4
    return 0;
}
