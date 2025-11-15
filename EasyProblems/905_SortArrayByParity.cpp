#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {

            // Move i forward until we find an odd number
            while (i < j && nums[i] % 2 == 0) {
                i++;
            }

            // Move j backward until we find an even number
            while (i < j && nums[j] % 2 != 0) {
                j--;
            }

            // Swap odd at i with even at j
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        return nums;
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 4};

    Solution s;
    vector<int> result = s.sortArrayByParity(nums);

    cout << "After sorting by parity: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
