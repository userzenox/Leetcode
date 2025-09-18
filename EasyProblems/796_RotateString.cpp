#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string temp = s + s;
        if (temp.find(goal) != string::npos) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";

    if (solution.rotateString(s, goal)) {
        cout << "True: '" << goal << "' is a rotation of '" << s << "'." << endl;
    } else {
        cout << "False: '" << goal << "' is NOT a rotation of '" << s << "'." << endl;
    }

    return 0;
}
