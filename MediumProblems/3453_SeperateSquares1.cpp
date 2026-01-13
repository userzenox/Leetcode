#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& squares, double mid_y, double total) {
        double botarea = 0.0;
        for (auto &sqr : squares) {
            double y = sqr[1];
            double l = sqr[2];

            if (mid_y >= y + l) {
                botarea += l * l;
            } else if (mid_y > y) {
                botarea += (mid_y - y) * l;
            }
        }
        return botarea >= total / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total = 0.0;
        double low = 1e18, high = -1e18;

        for (auto &sqr : squares) {
            double y = sqr[1];
            double l = sqr[2];

            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        while (high - low > 1e-5) {
            double mid_y = (high + low) / 2.0;
            if (check(squares, mid_y, total)) {
                high = mid_y;
            } else {
                low = mid_y;
            }
        }
        return (low + high) / 2.0;
    }
};

int main() {
    Solution sol;

    // Example input:
    vector<vector<int>> squares = {
        {0, 0, 2},
        {3, 1, 3},
        {1, 4, 2}
    };

    double ans = sol.separateSquares(squares);
    cout << "Cut at y = " << ans << endl;

    return 0;
}
