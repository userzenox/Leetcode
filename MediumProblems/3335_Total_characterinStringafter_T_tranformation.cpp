#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;

        vector<long long> count(26, 0);
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }

        for (int step = 0; step < t; step++) {
            vector<long long> newCount(26, 0);

            for (int i = 0; i < 26; i++) {
                if (count[i] == 0) continue;

                if (i == 25) {
                    newCount[0] = (newCount[0] + count[i]) % MOD;
                    newCount[1] = (newCount[1] + count[i]) % MOD;
                } else {
                    newCount[i + 1] = (newCount[i + 1] + count[i]) % MOD;
                }
            }

            count = newCount;
        }

        long long total = 0;
        for (int i = 0; i < 26; i++) {
            total = (total + count[i]) % MOD;
        }

        return static_cast<int>(total);
    }
};

int main() {
    Solution sol;

    string s;
    int t;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of transformations: ";
    cin >> t;

    int result = sol.lengthAfterTransformations(s, t);

    cout << "Length after " << t << " transformations: " << result << endl;

    return 0;
}
