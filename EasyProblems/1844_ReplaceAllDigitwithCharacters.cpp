#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        for(int i = 1; i < s.size(); i += 2) {
            // Convert digit character to integer by subtracting '0'
            char c = s[i-1] + (s[i] - '0');
            s[i] = c;
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "a1b2c3d4";
    cout << sol.replaceDigits(s) << endl; // Output should be "abbcddef"
    return 0;
}
