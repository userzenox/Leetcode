#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> s = score;

        int n = s.size();
        sort(s.begin(), s.end());   // ascending order

        int cnt = 1;
        unordered_map<int , string> m;

        // assign medals/ranks starting from highest score
        for(int i = n - 1; i >= 0; i--) {

            if(cnt == 1) {
                m[s[i]] = "Gold Medal";
            }
            else if(cnt == 2) {
                m[s[i]] = "Silver Medal";
            }
            else if(cnt == 3) {
                m[s[i]] = "Bronze Medal";
            }
            else {
                m[s[i]] = to_string(cnt);
            }

            cnt++;
        }

        vector<string> ans;

        // fill answers in original order
        for(int i = 0; i < n; i++) {
            ans.push_back(m[score[i]]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> score = {10, 3, 8, 9, 4};

    vector<string> result = sol.findRelativeRanks(score);

    cout << "Relative Ranks:" << endl;
    for(string &rank : result) {
        cout << rank << endl;
    }

    return 0;
}
