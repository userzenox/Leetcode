#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> answer(n, INT_MAX);
    int prev = -1000000;

    // Left to right pass
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) {
            prev = i;
        }
        answer[i] = min(answer[i], abs(i - prev));
    }

    // Right to left pass
    prev = 1000000;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == c) {
            prev = i;
        }
        answer[i] = min(answer[i], abs(prev - i));
    }

    return answer;
}

int main() {
    // Test case 1
    string s1 = "loveleetcode";
    char c1 = 'e';
    vector<int> result1 = shortestToChar(s1, c1);
    
    cout << "Input: s = \"" << s1 << "\", c = '" << c1 << "'" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // Test case 2
    string s2 = "aaab";
    char c2 = 'b';
    vector<int> result2 = shortestToChar(s2, c2);
    
    cout << "Input: s = \"" << s2 << "\", c = '" << c2 << "'" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
