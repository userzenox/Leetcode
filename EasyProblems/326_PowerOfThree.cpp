#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;

    // Test cases
    int test1 = 27;
    int test2 = 0;
    int test3 = 9;
    int test4 = 45;

    cout << "Is " << test1 << " a power of three? " << (sol.isPowerOfThree(test1) ? "Yes" : "No") << endl;
    cout << "Is " << test2 << " a power of three? " << (sol.isPowerOfThree(test2) ? "Yes" : "No") << endl;
    cout << "Is " << test3 << " a power of three? " << (sol.isPowerOfThree(test3) ? "Yes" : "No") << endl;
    cout << "Is " << test4 << " a power of three? " << (sol.isPowerOfThree(test4) ? "Yes" : "No") << endl;

    return 0;
}
