#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m1, m2;
        for (int i = 0; i < s.size(); i++) {
            if (m1.count(s[i]) && m1[s[i]] != t[i])
                return false;
            if (m2.count(t[i]) && m2[t[i]] != s[i])
                return false;
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (s1.size() != s2.size()) {
        cout << "Strings are not isomorphic (different lengths)." << endl;
        return 0;
    }

    bool result = sol.isIsomorphic(s1, s2);
    if (result)
        cout << "Strings are isomorphic." << endl;
    else
        cout << "Strings are not isomorphic." << endl;

    return 0;
}
