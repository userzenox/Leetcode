#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        // Insert borders: 1 and n+1 for horizontal, 1 and m+1 for vertical
        h.push_back(1);
        h.push_back(n + 1);
        v.push_back(1);
        v.push_back(m + 1);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        long long maxH = 0, maxV = 0;

        for(int i = 1; i < (int)h.size(); i++){
            maxH = max(maxH, (long long)(h[i] - h[i-1]));
        }
        for(int i = 1; i < (int)v.size(); i++){
            maxV = max(maxV, (long long)(v[i] - v[i-1]));
        }

        long long side = min(maxH, maxV);
        return side * side;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // grid rows/cols including bars
    int hcount, vcount;
    cin >> hcount >> vcount;

    vector<int> h(hcount), v(vcount);
    for(int i = 0; i < hcount; i++) cin >> h[i];
    for(int i = 0; i < vcount; i++) cin >> v[i];

    Solution sol;
    long long ans = sol.maximizeSquareHoleArea(n, m, h, v);
    cout << ans << "\n";

    return 0;
}
