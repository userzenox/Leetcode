#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int max_i = nums[0];      // Maximum value seen so far for i
        int max_diff = INT_MIN;   // Maximum (nums[i] - nums[j]) seen so far
        long long result = 0;

        for (int j = 1; j < n - 1; j++) {
            max_diff = max(max_diff, max_i - nums[j]);  // Max (nums[i] - nums[j])
            max_i = max(max_i, nums[j]);  // Update max_i for future comparisons

            if (max_diff != INT_MIN) {
                result = max(result, static_cast<long long>(max_diff) * nums[j + 1]);
            }
        }
        
        return result;
    }
};

int main() {
    vector<int> nums = {2, 3, 4,56,43,21,112}; // Test case
    
    Solution sol;
    long long result = sol.maximumTripletValue(nums);
    
    cout << "Output: " << result << endl; // Expected Output: 0
    
    return 0;
}
