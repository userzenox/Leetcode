#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i > 1; --i) {
        if (nums[i - 2] + nums[i - 1] > nums[i])
            return nums[i - 2] + nums[i - 1] + nums[i];
    }
    return 0;
}

int main() {
    vector<int> nums = {2, 1, 2};
    cout << largestPerimeter(nums) << endl; // Output: 5
    return 0;
}
