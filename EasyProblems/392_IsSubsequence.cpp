#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        bool val = false;
        if (s.size() == 0) {
            return true;
        }
        for (int j = 0; j < t.size(); j++) {
            if (i < s.size() && s[i] == t[j]) {
                if (i == s.size() - 1) {
                    val = true;
                    break;
                }
                i++;
            }
        }
        return val;
    }
};

int main() {
    Solution sol;

    // Example test cases
    string s1 = "abc";
    string t1 = "ahbgdc";

    string s2 = "axc";
    string t2 = "ahbgdc";

    bool result1 = sol.isSubsequence(s1, t1);
    bool result2 = sol.isSubsequence(s2, t2);

    cout << "Is \"" << s1 << "\" a subsequence of \"" << t1 << "\"? " << (result1 ? "Yes" : "No") << endl;
    cout << "Is \"" << s2 << "\" a subsequence of \"" << t2 << "\"? " << (result2 ? "Yes" : "No") << endl;

    return 0;
}
