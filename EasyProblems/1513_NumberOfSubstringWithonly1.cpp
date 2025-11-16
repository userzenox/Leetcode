#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        long long total = 0;
        const long long MOD = 1e9 + 7;

        for(int i = 0; i < s.size(); i++) {
            long long cnt = 0;

            // Count consecutive '1's
            while(i < s.size() && s[i] == '1') {
                cnt++;
                i++;
                total = (total + cnt) % MOD;  
            }
        }

        return total;
    }
};

int main() {
    Solution sol;

    string s;
    cin >> s;

    cout << sol.numSub(s) << endl;
    return 0;
}
