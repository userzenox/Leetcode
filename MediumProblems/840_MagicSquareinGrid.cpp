#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Only 3x3 subgrids can be magic squares
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {

        // Optimization: center must be 5
        if (grid[r + 1][c + 1] != 5)
            return false;

        bool seen[10] = {false};

        // Check numbers are 1–9 and unique
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen[val]) {
                    return false;
                }
                seen[val] = true;
            }
        }

        // Check rows
        for (int i = 0; i < 3; i++) {
            int sum = grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2];
            if (sum != 15) return false;
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            int sum = grid[r][c + j] + grid[r + 1][c + j] + grid[r + 2][c + j];
            if (sum != 15) return false;
        }

        // Check diagonals
        int diag1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int diag2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
        
        if (diag1 != 15 || diag2 != 15) return false;

        return true;
    }
};

// -------- MAIN FUNCTION --------
int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}
    };

    cout << "Number of magic squares: "
         << sol.numMagicSquaresInside(grid) << endl;

    return 0;
}
