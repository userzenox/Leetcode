#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (solution.isPowerOfFour(n)) {
        cout << n << " is a power of four." << endl;
    } else {
        cout << n << " is NOT a power of four." << endl;
    }

    return 0;
}
