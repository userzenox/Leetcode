#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            int count = 0;
            int x = i;
            while(x != 0) {
                if(x % 2 == 1) count++;
                x = x / 2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    vector<int> result = sol.countBits(n);

    cout << "Number of 1's in binary representations from 0 to " << n << ":\n";
    for(int i = 0; i <= n; i++) {
        cout << "countBits(" << i << ") = " << result[i] << endl;
    }

    return 0;
}
