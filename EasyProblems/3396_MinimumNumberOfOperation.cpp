#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        while (true) {
            vector<int> arr = nums; 
            sort(arr.begin(), arr.end());

            bool hasDuplicate = false;
            for (int i = 1; i < arr.size(); ++i) {
                if (arr[i] == arr[i - 1]) {
                    hasDuplicate = true;
                    break;
                }
            }

            if (!hasDuplicate) break;

            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            count++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 5, 7, 2, 3, 5, 4};
    int result1 = sol.minimumOperations(nums1);
    cout << "Minimum operations for [3, 5, 7, 2, 3, 5, 4]: " << result1 << endl;

    vector<int> nums2 = {1, 2, 2, 3, 4};
    int result2 = sol.minimumOperations(nums2);
    cout << "Minimum operations for [1, 2, 2, 3, 4]: " << result2 << endl;

    vector<int> nums3 = {1, 2, 3, 4};
    int result3 = sol.minimumOperations(nums3);
    cout << "Minimum operations for [1, 2, 3, 4]: " << result3 << endl;

    return 0;
}
