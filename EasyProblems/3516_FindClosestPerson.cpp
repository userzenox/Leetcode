#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(x - z);
        int dy = abs(y - z);
        if (dx == dy) return 0;
        return dx < dy ? 1 : 2;
    }
};

int main() {
    Solution sol;

    // Example 1
    int x1 = 1, y1 = 5, z1 = 2;
    cout << "Closest for (" << x1 << "," << y1 << "," << z1 << "): "
         << sol.findClosest(x1, y1, z1) << endl;

    // Example 2
    int x2 = 3, y2 = 6, z2 = 5;
    cout << "Closest for (" << x2 << "," << y2 << "," << z2 << "): "
         << sol.findClosest(x2, y2, z2) << endl;

    // Example 3 (equal distance)
    int x3 = 2, y3 = 6, z3 = 4;
    cout << "Closest for (" << x3 << "," << y3 << "," << z3 << "): "
         << sol.findClosest(x3, y3, z3) << endl;

    return 0;
}
