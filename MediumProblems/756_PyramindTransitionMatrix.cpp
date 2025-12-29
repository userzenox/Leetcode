#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Map each pair "AB" -> list of possible tops {'C', 'D', ...}
        unordered_map<string, vector<char>> mp;
        for (auto &s : allowed) {
            string key = s.substr(0, 2); // first two chars
            mp[key].push_back(s[2]);     // third char as possible top
        }

        unordered_map<string, bool> memo; // memo for rows
        return dfs(bottom, mp, memo);
    }

private:
    bool dfs(const string &row,
             unordered_map<string, vector<char>> &mp,
             unordered_map<string, bool> &memo) {

        if (row.size() == 1) return true;  // reached top successfully

        if (memo.count(row)) return memo[row];

        // generate all possible next rows from current row
        vector<string> nextRows;
        buildNextRows(row, 0, "", mp, nextRows);
        if (nextRows.empty()) return memo[row] = false;

        for (auto &nr : nextRows) {
            if (dfs(nr, mp, memo)) {
                return memo[row] = true;
            }
        }
        return memo[row] = false;
    }

    void buildNextRows(const string &row, int idx, string cur,
                       unordered_map<string, vector<char>> &mp,
                       vector<string> &res) {
        int n = row.size();
        if (idx == n - 1) {  // built full next row
            res.push_back(cur);
            return;
        }
        string key;
        key.push_back(row[idx]);
        key.push_back(row[idx + 1]);

        auto it = mp.find(key);
        if (it == mp.end()) return;  // no possible top for this pair

        for (char c : it->second) {
            buildNextRows(row, idx + 1, cur + c, mp, res);
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    string bottom1 = "ABC";
    vector<string> allowed1 = {"ABD", "BCE", "DEF", "FFF"};
    cout << boolalpha;
    cout << "Example 1: "
         << sol.pyramidTransition(bottom1, allowed1)
         << " (Expected: true)" << endl; // can build "ABCDE" -> "DEF" -> "F" [web:55][web:60]

    // Example 2
    string bottom2 = "AABA";
    vector<string> allowed2 = {"AAA", "AAB", "ABA", "ABB", "BAC"};
    cout << "Example 2: "
         << sol.pyramidTransition(bottom2, allowed2)
         << " (Expected: false)" << endl; // cannot reach single block [web:55][web:60]

    // Custom: small simple case
    string bottom3 = "AB";
    vector<string> allowed3 = {"ABC"};
    cout << "Example 3: "
         << sol.pyramidTransition(bottom3, allowed3)
         << " (Expected: true)" << endl;

    return 0;
}
