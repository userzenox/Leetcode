#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by start time
        sort(events.begin(), events.end());
        
        int n = events.size();
        
        // Precompute suffix maximum values: f[i] = max value from event i to end
        vector<int> f(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            f[i] = max(f[i + 1], events[i][2]);
        }
        
        int ans = 0;
        
        // For each event as first event, find best non-overlapping second event
        for (const auto& e : events) {
            int v = e[2];
            int endTime = e[1];
            
            // Binary search for first event starting after endTime
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) / 2;
                if (events[mid][0] > endTime) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            // If found valid second event, add its max value
            if (left < n) {
                v += f[left];
            }
            
            ans = max(ans, v);
        }
        
        return ans;
    }
};

// Main function for testing
int main() {
    Solution sol;
    
    // Test case 1: [[1,3,2],[4,5,2],[2,4,3]]
    vector<vector<int>> events1 = {{1,3,2},{4,5,2},{2,4,3}};
    cout << "Test 1: " << sol.maxTwoEvents(events1) << " (Expected: 4)" << endl;
    
    // Test case 2: [[1,3,2],[4,5,2],[1,5,5]]
    vector<vector<int>> events2 = {{1,3,2},{4,5,2},{1,5,5}};
    cout << "Test 2: " << sol.maxTwoEvents(events2) << " (Expected: 5)" << endl;
    
    // Test case 3: [[1,5,3],[1,5,1],[6,6,5]]
    vector<vector<int>> events3 = {{1,5,3},{1,5,1},{6,6,5}};
    cout << "Test 3: " << sol.maxTwoEvents(events3) << " (Expected: 8)" << endl;
    
    // Test case 4: Single high value event better than pairs
    vector<vector<int>> events4 = {{1,2,20},{4,5,1},{6,7,1}};
    cout << "Test 4: " << sol.maxTwoEvents(events4) << " (Expected: 20)" << endl;
    
    return 0;
}
