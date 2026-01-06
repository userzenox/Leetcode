#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int negativeCount = 0;
        long long sum = 0;
        int mini = INT_MAX;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = abs(matrix[i][j]);

                if (matrix[i][j] < 0) {
                    negativeCount++;
                }

                mini = min(mini, val);
                sum += val;
            }
        }

        if (negativeCount % 2 != 0) {
            return sum - 2LL * mini;
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, -1},
        {-1, 1}
    };

    long long result = sol.maxMatrixSum(matrix);
    cout << "Maximum Matrix Sum: " << result << endl;

    return 0;
}
