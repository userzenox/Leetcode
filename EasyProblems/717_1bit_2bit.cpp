#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while (i < n - 1) {
            if (bits[i] == 1) {
                i += 2;  // two-bit character
            } else {
                i += 1;  // one-bit character
            }
        }

        // If pointer ends exactly on last index → last char is 1-bit (0)
        return i == n - 1;
    }
};

int main() {
    int n;
    cin >> n;   // number of bits
    vector<int> bits(n);

    for (int i = 0; i < n; i++) {
        cin >> bits[i];
    }

    Solution s;
    bool result = s.isOneBitCharacter(bits);

    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
