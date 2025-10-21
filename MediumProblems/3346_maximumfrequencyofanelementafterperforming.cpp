#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEL = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxEL + 2, 0);

        // Frequency count
        for (int x : nums) freq[x]++;

        // Cumulative sum
        for (int i = 1; i <= maxEL; i++) {
            freq[i] += freq[i - 1];
        }

        int result = 0;
        for (int target = 0; target <= maxEL; target++) {
            // Skip if this target value isn't present in array
            if ((freq[target] - (target > 0 ? freq[target - 1] : 0)) == 0)
                continue;

            int leftNum = target - k;
            int rightNum = target + k;

            if (rightNum > maxEL) rightNum = maxEL;
            if (leftNum < 0) leftNum = 0;

            int totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);
            int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);
            int needConversion = totalCount - targetCount;
            int maxPossibleFreq = targetCount + min(needConversion, numOperations);

            result = max(result, maxPossibleFreq);
        }
        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 4, 5};
    int k = 2, numOperations = 2;
    cout << sol.maxFrequency(nums, k, numOperations) << endl;
    // Output: 2
    return 0;
}
