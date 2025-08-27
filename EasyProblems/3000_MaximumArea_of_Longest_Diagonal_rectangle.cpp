#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int bestDiag2 = -1;
        int bestArea = -1;

        for (auto &d : dimensions) {
            int a = d[0], b = d[1];
            int diag2 = a * a + b * b;
            int area  = a * b;

            if (diag2 > bestDiag2 || (diag2 == bestDiag2 && area > bestArea)) {
                bestDiag2 = diag2;
                bestArea  = area;
            }
        }
        return bestArea;
    }
};

int main() {
    // Example input: vector of rectangles with [length, width]
    vector<vector<int>> dimensions = {{3, 4}, {5, 12}, {8, 15}, {7, 24}};
    Solution sol;
    int result = sol.areaOfMaxDiagonal(dimensions);
    cout << "Area of rectangle with maximum diagonal: " << result << endl;
    return 0;
}
