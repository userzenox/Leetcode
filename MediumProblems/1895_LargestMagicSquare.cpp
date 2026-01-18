#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Prefix sums for rows and columns
        vector<vector<int>> row(m, vector<int>(n+1, 0));
        vector<vector<int>> col(m+1, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[i][j+1] = row[i][j] + grid[i][j];
            }
        }

        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                col[i+1][j] = col[i][j] + grid[i][j];
            }
        }

        auto getRowSum = [&](int r, int c1, int c2){
            return row[r][c2+1] - row[r][c1];
        };

        auto getColSum = [&](int c, int r1, int r2){
            return col[r2+1][c] - col[r1][c];
        };

        int ans = 1;
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                // Try largest possible size from current cell
                int maxK = min(m - r, n - c);
                for(int k = maxK; k >= 2; k--){
                    int target = -1;
                    bool good = true;

                    // Check rows
                    for(int i = 0; i < k; i++){
                        int s = getRowSum(r+i, c, c+k-1);
                        if(target < 0) target = s;
                        else if(target != s){
                            good = false;
                            break;
                        }
                    }
                    if(!good) continue;

                    // Check cols
                    for(int j = 0; j < k; j++){
                        int s = getColSum(c+j, r, r+k-1);
                        if(target != s){
                            good = false;
                            break;
                        }
                    }
                    if(!good) continue;

                    // Check main diagonal
                    int d1 = 0;
                    for(int i = 0; i < k; i++){
                        d1 += grid[r+i][c+i];
                    }
                    if(d1 != target) continue;

                    // Check anti diagonal
                    int d2 = 0;
                    for(int i = 0; i < k; i++){
                        d2 += grid[r+i][c+k-1-i];
                    }
                    if(d2 != target) continue;

                    ans = max(ans, k);
                    // No need to check smaller k for this cell once found
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    // Example usage:
    vector<vector<int>> grid = {
        {7,1,4,5,6},
        {2,5,1,6,4},
        {1,5,4,3,2},
        {1,2,7,3,4}
    };

    Solution sol;
    int result = sol.largestMagicSquare(grid);
    cout << result << endl;
    return 0;
}
