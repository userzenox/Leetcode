#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, threshold;
    cin >> m >> n >> threshold;

    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    // Build 2D prefix sum (1-indexed)
    vector<vector<int>> ps(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            ps[i][j] = mat[i-1][j-1]
                     + ps[i-1][j]
                     + ps[i][j-1]
                     - ps[i-1][j-1];
        }
    }

    auto getSum = [&](int r1, int c1, int r2, int c2) {
        // r1,c1,r2,c2 inclusive on 1-indexed
        return ps[r2][c2] - ps[r1-1][c1-1] - ps[r1-1][c2] + ps[r2][c1-1];
    };

    int ans = 0;
    int maxK = min(m, n);

    // Binary search on each cell
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            int low = ans + 1;
            int high = maxK;
            while(low <= high) {
                int mid = (low + high) / 2;
                int r2 = i + mid - 1;
                int c2 = j + mid - 1;
                if(r2 <= m && c2 <= n) {
                    int s = getSum(i, j, r2, c2);
                    if(s <= threshold) {
                        ans = max(ans, mid);
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                } else {
                    high = mid - 1;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
