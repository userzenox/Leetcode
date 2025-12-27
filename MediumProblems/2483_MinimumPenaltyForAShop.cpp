#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> ysum(n+1, 0);
        vector<int> nsum(n+1, 0);
        
        // Build prefix sums for 'Y' and 'N' counts
        for(int i = 1; i <= n; i++) {
            if(customers[i-1] == 'Y') {
                ysum[i] = ysum[i-1] + 1;
                nsum[i] = nsum[i-1];
            } else {
                ysum[i] = ysum[i-1];
                nsum[i] = nsum[i-1] + 1;
            }
        }
        
        int mincost = INT_MAX;
        int time = 0;
        
        // Check all possible closing times (0 to n)
        for(int i = 0; i <= n; i++) {
            // Penalty = N's in open hours (0 to i-1) + Y's in closed hours (i to n-1)
            int cost = nsum[i] + (ysum[n] - ysum[i]);
            
            if(cost < mincost) {
                mincost = cost;
                time = i;
            }
        }
        
        return time;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: "YYNY"
    cout << "Test case 1: \"YYNY\" -> " << sol.bestClosingTime("YYNY") << endl;  // Expected: 2
    
    // Test case 2: "NNNN"
    cout << "Test case 2: \"NNNN\" -> " << sol.bestClosingTime("NNNN") << endl;  // Expected: 0
    
    // Test case 3: "YYYY"
    cout << "Test case 3: \"YYYY\" -> " << sol.bestClosingTime("YYYY") << endl;  // Expected: 4
    
    // Test case 4: "PP" (only Y/N allowed, but testing edge case)
    cout << "Test case 4: \"YNNY\" -> " << sol.bestClosingTime("YNNY") << endl;  // Expected: 1
    
    return 0;
}
