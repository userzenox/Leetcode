#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> ans;

        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int left = max(0, j - k);
                int right = min(n - 1, j + k);
                for (int i = left; i <= right; ++i) {
                    if (!visited[i]) {
                        visited[i] = true;
                        ans.push_back(i);
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {1, 2, 3, 4, 2, 5};
    int key = 2;
    int k = 1;

    vector<int> result = sol.findKDistantIndices(nums, key, k);

    // Print the result
    cout << "K-distant indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
