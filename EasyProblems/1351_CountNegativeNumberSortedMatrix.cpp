#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = cols - 1; j >= 0; j--) {
                if(grid[i][j] < 0) {
                    cnt++;
                } else {
                    break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    // Test case 1: LeetCode sample
    vector<vector<int>> grid1 = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };
    cout << "Test 1: " << Solution().countNegatives(grid1) << " (Expected: 8)" << endl; // Output: 8 [web:21][web:34]
    
    // Test case 2: 4 negatives
    vector<vector<int>> grid2 = {
        {-3, -2, -1, 1},
        {-2, -1, 0, 2},
        {-1, 0, 1, 3},
        {0, 1, 2, 4}
    };
    cout << "Test 2: " << Solution().countNegatives(grid2) << " (Expected: 4)" << endl; // Output: 4 [web:34]
    
    // Test case 3: No negatives
    vector<vector<int>> grid3 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    cout << "Test 3: " << Solution().countNegatives(grid3) << " (Expected: 0)" << endl; // Output: 0 [web:34]
    
    return 0;
}
