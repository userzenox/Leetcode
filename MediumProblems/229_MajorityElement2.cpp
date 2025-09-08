#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 1;  // Initialize differently to avoid confusion
        vector<int> ans;

        for (auto n : nums) {
            if (cnt1 > 0 && n == ele1) {
                cnt1++;
            } else if (cnt2 > 0 && n == ele2) {
                cnt2++;
            } else if (cnt1 == 0) {
                ele1 = n;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                ele2 = n;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0; 
        cnt2 = 0;

        for (auto n : nums) {
            if (n == ele1) cnt1++;
            else if (n == ele2) cnt2++;
        }

        int threshold = nums.size() / 3;
        if (cnt1 > threshold) ans.push_back(ele1);
        if (cnt2 > threshold) ans.push_back(ele2);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 2, 3};
    vector<int> result = sol.majorityElement(nums);

    cout << "Majority elements (> n/3 times): ";
    for (int el : result) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}
