#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                int sum1 = prefix[i];
                int sum2 = prefix[n] - prefix[i+1];
                if(sum1 == sum2) ans += 2;
                else if(abs(sum1 - sum2) == 1) ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    // Example vector
    vector<int> nums = {1, 0, 2, 0, 1};
    Solution sol;
    int result = sol.countValidSelections(nums);
    cout << "Valid selections: " << result << endl;
    return 0;
}
