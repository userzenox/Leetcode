#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int maxsum = 0;

        while (i < j) {
            int sum = nums[i] + nums[j];
            maxsum = max(maxsum, sum);
            i++;
            j--;
        }

        return maxsum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.minPairSum(nums) << endl;

    return 0;
}
