#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() != 2) {
            string temp = "";
            for (int i = 1; i < s.size(); i++) {
                char c1 = s[i];
                char c2 = s[i - 1];
                int d = ((c1 - '0') + (c2 - '0')) % 10;
                temp = temp + char(d + '0'); // Convert int to char digit
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a numeric string: ";
    cin >> input;

    if (sol.hasSameDigits(input)) {
        cout << "The final two digits are the same." << endl;
    } else {
        cout << "The final two digits are different." << endl;
    }

    return 0;
}
