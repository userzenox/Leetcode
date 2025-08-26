#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return {};
        
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> ans;
        ans.reserve(rows * cols);

        int r = 0, c = 0;
        bool direction = true; // true means up-right, false means down-left

        while(ans.size() < rows * cols) {
            ans.push_back(mat[r][c]);

            if(direction) { 
                if(c == cols - 1) {
                    r++; 
                    direction = false;
                }
                else if(r == 0) {
                    c++; 
                    direction = false;
                }
                else {
                    r--;
                    c++;
                }
            }
            else { 
                if(r == rows - 1) {
                    c++;
                    direction = true;
                }
                else if(c == 0) {
                    r++;
                    direction = true;
                }
                else {
                    r++;
                    c--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    vector<int> result = sol.findDiagonalOrder(mat);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
