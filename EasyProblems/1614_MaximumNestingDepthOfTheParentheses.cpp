#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0;      // current depth
        int maxcount = 0;   // maximum depth

        for (char c : s) {
            if (c == '(') {
                count++;
                maxcount = max(maxcount, count);
            } else if (c == ')') {
                count--;
            }
        }
        return maxcount;
    }
};

int main() {
    Solution sol;
    string s = "((1+(2*3))+((8)/4))+1";
    cout << sol.maxDepth(s) << endl;  // Output: 3
    return 0;
}
