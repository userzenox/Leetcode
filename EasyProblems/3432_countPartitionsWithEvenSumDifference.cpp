#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int n = nums.size();
        vector<int> suffix(n);

        // build suffix sum
        int sum = 0;
        for(int i = n-1; i >= 0; i--) {
            sum += nums[i];
            suffix[i] = sum;
        }

        int leftSum = 0;
        int count = 0;

        // check valid partitions
        for(int i = 0; i < n-1; i++){
            leftSum += nums[i];

            if((leftSum % 2) == (suffix[i+1] % 2)){
                count++;
            }
        }

        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example input
    vector<int> nums = {1, 2, 3};

    Solution sol;
    int result = sol.countPartitions(nums);

    cout << "Number of valid partitions: " << result << endl;

    return 0;
}
