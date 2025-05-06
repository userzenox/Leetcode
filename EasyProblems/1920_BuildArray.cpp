#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

                // vector<int> ans(n);
        // for(int i=0; i<n;i++){
        //     ans[i] = nums[nums[i]];
        // }
        // return ans;

        for (int i = 0; i < n; ++i) {
            nums[i] += (nums[nums[i]] % n) * n;
        }

        for (int i = 0; i < n; ++i) {
            nums[i] /= n;
        }

        return nums;
    }
};

int main() {
    vector<int> nums = {5, 0, 1, 2, 3, 4}; // Example input
    Solution sol;
    vector<int> result = sol.buildArray(nums);

    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
