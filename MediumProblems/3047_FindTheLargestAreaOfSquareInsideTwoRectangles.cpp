#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<int>& A, vector<int>& B) {
        // A and B are rectangles defined as [x1, y1, x2, y2]
        long long x1 = A[0], y1 = A[1], x2 = A[2], y2 = A[3];
        long long X1 = B[0], Y1 = B[1], X2 = B[2], Y2 = B[3];

        // Compute overlap
        long long ox1 = max(x1, X1);
        long long oy1 = max(y1, Y1);
        long long ox2 = min(x2, X2);
        long long oy2 = min(y2, Y2);

        if (ox1 >= ox2 || oy1 >= oy2) {
            return 0; // no overlap
        }

        long long width = ox2 - ox1;
        long long height = oy2 - oy1;
        long long side = min(width, height);
        return side * side;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example I/O format:
    // Input:
    // x1 y1 x2 y2
    // X1 Y1 X2 Y2
    //
    // Example:
    // 0 0 5 4
    // 1 1 6 6

    vector<int> A(4), B(4);
    for (int i = 0; i < 4; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> B[i];

    Solution sol;
    long long ans = sol.largestSquareArea(A, B);
    cout << ans << "\n";
    return 0;
}
