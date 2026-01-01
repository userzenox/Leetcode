#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += 1;          // add 1
            digits[i] %= 10;         // becomes 0 if it was 10
            if (digits[i] != 0) {    // no carry, done
                return digits;
            }
        }
        // all digits were 9, e.g., 9, 99, 999 -> 1000...
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    int n;
    cin >> n;               // number of digits
    vector<int> digits(n);
    for (int i = 0; i < n; ++i) {
        cin >> digits[i];   // each digit (0-9)
    }

    Solution sol;
    vector<int> ans = sol.plusOne(digits);

    for (int d : ans) {
        cout << d << " ";
    }
    cou
