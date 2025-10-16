#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;

        // Count occurrences of each remainder modulo value
        for (int num : nums) {
            int r = ((num % value) + value) % value; // ensures non-negative remainder
            mp[r]++;
        }

        int MEX = 0;

        // Find smallest missing non-negative integer (MEX)
        while (mp[MEX % value] > 0) {
            mp[MEX % value]--;
            MEX++;
        }

        return MEX;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, -10, 7, 13, 6, 8};
    int value = 5;

    // Function call
    int ans = sol.findSmallestInteger(nums, value);

    cout << "Smallest Missing Non-negative Integer After Operations: " << ans << endl;

    return 0;
}
