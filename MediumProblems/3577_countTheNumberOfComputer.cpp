#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long result = 1;
        int n = complexity.size();
        const long long MOD = 1e9 + 7;

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
            result = (result * i) % MOD;
        }

        return (int)result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> complexity(n);
    for (int i = 0; i < n; i++) {
        cin >> complexity[i];
    }

    Solution sol;
    cout << sol.countPermutations(complexity) << endl;

    return 0;
}
