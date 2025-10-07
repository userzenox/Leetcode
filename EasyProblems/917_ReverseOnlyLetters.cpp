#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalpha(s[i])) ++i;
            while (i < j && !isalpha(s[j])) --j;
            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "a-bC-dEf-ghIj";
    cout << sol.reverseOnlyLetters(s) << endl; // Output: "j-Ih-gfE-dCba"
    return 0;
}
