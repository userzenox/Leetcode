#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxLen = 0;

        for (int num : nums) {
            count[num]++;
        }

        for (auto& [num, freq] : count) {
            if (count.find(num + 1) != count.end()) {
                maxLen = max(maxLen, freq + count[num + 1]);
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};

    int result = sol.findLHS(nums);

    cout << "The length of the longest harmonious subsequence is: " << result << endl;

    return 0;
}
