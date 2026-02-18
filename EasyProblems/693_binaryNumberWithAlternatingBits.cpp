#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = n ^ (n >> 1);
        long long ans = x & (x + 1);
        return ans == 0;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.hasAlternatingBits(n)) {
        cout << "True - The number has alternating bits." << endl;
    } else {
        cout << "False - The number does not have alternating bits." << endl;
    }

    return 0;
}
