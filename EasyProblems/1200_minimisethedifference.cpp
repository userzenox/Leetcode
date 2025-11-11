#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        if (arr.size() < 2) return ans; // handle edge case

        sort(arr.begin(), arr.end());

        int mini = INT_MAX;

        // Step 1: Find the minimum absolute difference
        for (int i = 1; i < arr.size(); i++) {
            mini = min(mini, arr[i] - arr[i - 1]);
        }

        // Step 2: Collect all pairs with that difference
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == mini) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    Solution sol;

    // Example input
    vector<int> arr = {4, 2, 1, 3};

    // Get result
    vector<vector<int>> result = sol.minimumAbsDifference(arr);

    // Print result
    cout << "Pairs with minimum absolute difference:\n";
    for (auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}
