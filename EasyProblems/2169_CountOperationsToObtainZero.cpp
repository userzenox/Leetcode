#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;

        while (num1 != 0 && num2 != 0) {
            if (num1 > num2) {
                num1 = num1 - num2;
            } else {
                num2 = num2 - num1;
            }
            cnt++;
        }

        return cnt;
    }
};

int main() {
    int num1, num2;
    cout << "Enter num1 and num2: ";
    cin >> num1 >> num2;

    Solution obj;
    int result = obj.countOperations(num1, num2);

    cout << "Number of operations: " << result << endl;

    return 0;
}
