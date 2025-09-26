#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // If string is empty after trimming
        if (i == n) return 0;

        // 2. Handle sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits to integer
        long num = 0;  // use long to detect overflow
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4. Clamp if overflow happens
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sign * num);
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<string> inputs = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332"
    };

    for (auto &s : inputs) {
        cout << "Input: \"" << s << "\"  => Output: " 
             << sol.myAtoi(s) << endl;
    }

    return 0;
}
