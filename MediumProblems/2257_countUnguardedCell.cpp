#include <vector>
#include <iostream>
using namespace std;

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));

    // Mark wall cells as 1
    for (auto i : walls)
        grid[i[0]][i[1]] = 1;

    // Mark guard cells as 1
    for (auto i : guards)
        grid[i[0]][i[1]] = 1;

    // Spread guard vision in all directions
    for (auto i : guards) {
        int x, y;

        // left
        x = i[0]; y = i[1] - 1;
        while (y >= 0 && grid[x][y] != 1) {
            grid[x][y] = 2;
            y--;
        }

        // right
        x = i[0]; y = i[1] + 1;
        while (y < n && grid[x][y] != 1) {
            grid[x][y] = 2;
            y++;
        }

        // up
        x = i[0] - 1; y = i[1];
        while (x >= 0 && grid[x][y] != 1) {
            grid[x][y] = 2;
            x--;
        }

        // down
        x = i[0] + 1; y = i[1];
        while (x < m && grid[x][y] != 1) {
            grid[x][y] = 2;
            x++;
        }
    }

    // Count unguarded cells: cells with value 0
    int cnt = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 0)
                cnt++;

    return cnt;
}

int main() {
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};
    cout << countUnguarded(m, n, guards, walls) << endl;
    return 0;
}
