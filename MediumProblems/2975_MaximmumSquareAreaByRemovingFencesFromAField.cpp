#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        int n = (int)hFences.size();
        int m = (int)vFences.size();

        unordered_set<int> hs;
        hs.reserve(n * n);

        // Compute all horizontal distances
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                hs.insert(hFences[j] - hFences[i]);
            }
        }

        long long ans = -1;

        // Compute all vertical distances and check intersection
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int d = vFences[j] - vFences[i];
                if (hs.count(d)) {
                    long long sq = 1LL * d * d;
                    if (sq > ans) ans = sq;
                }
            }
        }

        return (int)ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format example (customizable)
    // nH nV
    // hFences...
    // vFences...
    int nH, nV;
    cin >> nH >> nV;

    vector<int> hFences(nH), vFences(nV);
    for (int i = 0; i < nH; i++) cin >> hFences[i];
    for (int i = 0; i < nV; i++) cin >> vFences[i];

    Solution sol;
    int ans = sol.maximizeSquareArea(hFences, vFences);

    cout << ans << "\n";
    return 0;
}
