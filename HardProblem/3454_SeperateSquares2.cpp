#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
using namespace std;

class Solution {
public:
    bool checkY(vector<vector<int>>& squares, double mid_y, double total) {
        double bottomArea = 0.0;
        for (auto &sqr : squares) {
            double y = sqr[1];
            double l = sqr[2];

            if (mid_y >= y + l) {
                bottomArea += l * l;
            } else if (mid_y > y) {
                bottomArea += (mid_y - y) * l;
            }
        }
        return bottomArea >= total / 2.0;
    }

    bool checkX(vector<vector<int>>& squares, double mid_x, double total) {
        double leftArea = 0.0;
        for (auto &sqr : squares) {
            double x = sqr[0];
            double l = sqr[2];

            if (mid_x >= x + l) {
                leftArea += l * l;
            } else if (mid_x > x) {
                leftArea += (mid_x - x) * l;
            }
        }
        return leftArea >= total / 2.0;
    }

    double binaryY(vector<vector<int>>& squares, double total) {
        double low = numeric_limits<double>::max();
        double high = numeric_limits<double>::lowest();

        for (auto &sqr : squares) {
            double y = sqr[1];
            double l = sqr[2];
            low = min(low, y);
            high = max(high, y + l);
        }

        double result = low;
        while (high - low > 1e-5) {
            double mid = (high + low) / 2.0;
            if (checkY(squares, mid, total)) {
                result = mid;
                high = mid;
            } else {
                low = mid;
            }
        }
        return result;
    }

    double binaryX(vector<vector<int>>& squares, double total) {
        double low = numeric_limits<double>::max();
        double high = numeric_limits<double>::lowest();

        for (auto &sqr : squares) {
            double x = sqr[0];
            double l = sqr[2];
            low = min(low, x);
            high = max(high, x + l);
        }

        double result = low;
        while (high - low > 1e-5) {
            double mid = (high + low) / 2.0;
            if (checkX(squares, mid, total)) {
                result = mid;
                high = mid;
            } else {
                low = mid;
            }
        }
        return result;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total = 0.0;
        for (auto &sqr : squares) {
            double l = sqr[2];
            total += l * l;
        }

        double ansY = binaryY(squares, total);
        double ansX = binaryX(squares, total);

        return min(ansX, ansY);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> squares(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> squares[i][0] >> squares[i][1] >> squares[i][2];
    }

    Solution sol;
    double ans = sol.separateSquares(squares);

    cout << fixed << setprecision(5) << ans << "\n";
    return 0;
}
