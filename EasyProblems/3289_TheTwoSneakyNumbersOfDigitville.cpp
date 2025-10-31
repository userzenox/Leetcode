#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> ans;
        ans.reserve(nums.size());  // avoid reallocations

        for (int num : nums) {
            if (!seen.insert(num).second)  // insert() returns {iterator, bool}
                ans.push_back(num);
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    vector<int> duplicates = obj.getSneakyNumbers(nums);

    cout << "Sneaky numbers (duplicates): ";
    for (int x : duplicates)
        cout << x << " ";
    cout << endl;

    return 0;
}
