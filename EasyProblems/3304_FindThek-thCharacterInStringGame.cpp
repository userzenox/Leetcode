#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
         string s = "a";

        while (s.size() < k) {
            string str = "";
            for (char c : s) {
                char ch = (c == 'z') ? 'a' : c + 1;
                str += ch;
            }
            s += str;
        }

        return s[k - 1];
    }
};

int main() {
    Solution sol;
    int k;

    cout << "Enter value of k: ";
    cin >> k;

    char result = sol.kthCharacter(k);

    cout << "The " << k << "-th character is: " << result << endl;

    return 0;
}
