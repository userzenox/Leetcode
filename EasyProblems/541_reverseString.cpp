#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // Iterate every 2k characters
        for (int i = 0; i < s.size(); i += 2 * k) {
            // Find the range to reverse
            int left = i;
            int right = min(i + k - 1, (int)s.size() - 1);

            // Reverse the first k characters
            while (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    string s;
    int k;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter value of k: ";
    cin >> k;

    string result = sol.reverseStr(s, k);

    cout << "Reversed string: " << result << endl;

    return 0;
}
