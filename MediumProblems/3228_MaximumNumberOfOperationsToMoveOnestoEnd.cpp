#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxOperations(string s) {
        long long operation = 0;
        long long count = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                count++;
            }

            if (s[i] == '1' && s[i + 1] == '0') {
                operation += count;
            }
        }

        return operation;
    }
};

int main() {
    string s;
    cout << "Enter binary string: ";
    cin >> s;

    Solution obj;
    cout << "Maximum number of operations: " << obj.maxOperations(s) << endl;

    return 0;
}
