#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;
    vector<vector<int>> t;

    string states[12] = {"RYG", "RGY", "YRG", "YGR", "GRY", "GYR", 
                         "RYR", "YRY", "GRG", "RGR", "YGY", "GYG"};

    int solve(int n, int prev) {
        if (n == 0) {
            return 1;
        }

        if (t[n][prev] != -1) {
            return t[n][prev];
        }

        int result = 0;
        string last = states[prev];

        for (int curr = 0; curr < 12; curr++) {
            if (curr == prev) {
                continue;
            }

            string currpat = states[curr];
            bool conflict = false;

            for (int c = 0; c < 3; c++) {
                if (currpat[c] == last[c]) {
                    conflict = true;
                    break;
                }
            }

            if (!conflict) {
                result = (result + (long long)solve(n - 1, curr)) % M;
            }
        }
        return t[n][prev] = result;
    }

    int numOfWays(int n) {
        t.assign(n + 1, vector<int>(12, -1));  // Fix: n+1 size

        int result = 0;
        for (int i = 0; i < 12; i++) {
            result = (result + (long long)solve(n - 1, i)) % M;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test cases from LeetCode 1411
    cout << sol.numOfWays(1) << endl;  // Expected: 12
    cout << sol.numOfWays(2) << endl;  // Expected: 54
    cout << sol.numOfWays(3) << endl;  // Expected: 246
    
    return 0;
}
