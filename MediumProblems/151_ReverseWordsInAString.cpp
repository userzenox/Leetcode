#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        stack<string> st;
        
        for (int i = 0; i < s.size(); i++) {
            // If current character is not a space, add it to the current word
            if (s[i] != ' ') {
                str += s[i];
            }
            else {
                // If current word is not empty, push it to the stack
                if (str != "") {
                    st.push(str);
                    str = "";
                }
                // Skip consecutive spaces
                while (i + 1 < s.size() && s[i + 1] == ' ') {
                    i++;
                }
            }
        }
        // Push the last word if it exists
        if (str != "") {
            st.push(str);
        }

        // Build the reversed string by popping words from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += ' ';
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "  Hello   world  this is  C++  ";
    string reversed = sol.reverseWords(input);
    cout << "Reversed words: \"" << reversed << "\"" << endl;
    return 0;
}
