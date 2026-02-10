#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        unordered_map<int, int> prefixIndex;
        int prefixSum = 0;
        int maxLength = 0;

        // Prefix sum 0 at index -1
        prefixIndex[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] % 2 == 0) {
                prefixSum += 1;   // even
            } else {
                prefixSum -= 1;   // odd
            }

            // If prefix sum seen before
            if (prefixIndex.find(prefixSum) != prefixIndex.end()) {
                maxLength = max(maxLength, i - prefixIndex[prefixSum]);
            } else {
                prefixIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.longestBalanced(nums);

    cout << "Longest balanced subarray length: " << result << endl;

    return 0;
}
