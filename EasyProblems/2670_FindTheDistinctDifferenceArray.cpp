#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    // Helper function to count distinct elements in nums[s..e]
    int finddistinct(int s, int e, vector<int>& nums) {
        set<int> st;
        int count = 0;
        for (int i = s; i <= e; i++) {
            if (st.count(nums[i]) == 0) {
                st.insert(nums[i]);
                count++;
            }
        }
        return count;
    }

    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int countpre = finddistinct(0, i, nums);

            int countsuf = 0;
            if (i + 1 < n) {
                countsuf = finddistinct(i + 1, n - 1, nums);
            }
            int sum = countpre - countsuf;
            ans.push_back(sum);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // Sample input
    vector<int> nums = {3, 2, 3, 4, 2};
    vector<int> result = sol.distinctDifferenceArray(nums);
    cout << "Result: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
