#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndexMap;
        modIndexMap[0] = -1;  // handle subarray starting at index 0
        
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int mod = (k == 0) ? sum : sum % k;
            
            if (modIndexMap.count(mod)) {
                if (i - modIndexMap[mod] >= 2) return true;
            } else {
                modIndexMap[mod] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;

    bool result = solution.checkSubarraySum(nums, k);

    if (result) {
        cout << "True: There exists a continuous subarray of size at least 2 whose sum is a multiple of " << k << "." << endl;
    } else {
        cout << "False: No such subarray exists." << endl;
    }

    return 0;
}
