#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        int count = 0;
        for (char c : brokenLetters) {
            st.insert(c);
        }
        text += ' ';
        bool word = true;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] != ' ') {
                if (st.count(text[i]) > 0) {
                    word = false;
                }
            } else {
                if (word != false) {
                    count++;
                }
                word = true;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    
    string text1 = "hello world";
    string broken1 = "ad";
    cout << "Test 1: " << solution.canBeTypedWords(text1, broken1) << endl; // Output: 1
    
    string text2 = "leet code";
    string broken2 = "e";
    cout << "Test 2: " << solution.canBeTypedWords(text2, broken2) << endl; // Output: 0

    string text3 = "typing test example";
    string broken3 = "xyz";
    cout << "Test 3: " << solution.canBeTypedWords(text3, broken3) << endl; // Output: 3

    return 0;
}
