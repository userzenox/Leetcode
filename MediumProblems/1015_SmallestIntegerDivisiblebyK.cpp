#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {

        // If k has factor 2 or 5, repunit (111..) will never be divisible
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int rem = 0;

        // At most k iterations because remainder will repeat
        for (int i = 1; i <= k; i++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    
    int k;
    cout << "Enter value of k: ";
    cin >> k;

    int ans = sol.smallestRepunitDivByK(k);
    cout << "Smallest length of repunit divisible by " << k << " is: " << ans << endl;

    return 0;
}
