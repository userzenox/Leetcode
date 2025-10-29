#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int sum = 0;
        int i = 0;

        // keep adding powers of 2 until sum >= n
        while (sum < n) {
            sum += (1 << i); // faster than pow(2, i)
            i++;
        }

        return sum;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Smallest number >= " << n << " formed by sum of powers of 2 is: "
         << sol.smallestNumber(n) << endl;

    return 0;
}
