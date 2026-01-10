#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minimumDeleteSum(const string &s1, const string &s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases: delete remaining suffixes
    for (int i = n - 1; i >= 0; --i) {
        dp[i][m] = dp[i + 1][m] + s1[i];
    }
    for (int j = m - 1; j >= 0; --j) {
        dp[n][j] = dp[n][j + 1] + s2[j];
    }

    // Fill DP bottom-up
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            } else {
                dp[i][j] = min(
                    s1[i] + dp[i + 1][j],
                    s2[j] + dp[i][j + 1]
                );
            }
        }
    }

    return dp[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;

    int result = minimumDeleteSum(s1, s2);
    cout << "Minimum ASCII Delete Sum: " << result << "\n";

    return 0;
}
