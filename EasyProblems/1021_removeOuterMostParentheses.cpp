#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int d = 0; // depth counter

        for (char c : s) {
            if (c == '(') {
                if (d > 0) {   // only add if not the outermost '('
                    ans += c;
                }
                d++;
            } else {
                d--;
                if (d > 0) {   // only add if not the outermost ')'
                    ans += c;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "(()())(())(()(()))";
    cout << sol.removeOuterParentheses(s) << endl;  
    // Output: "()()()()(())"
    return 0;
}
