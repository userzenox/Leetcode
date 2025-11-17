#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;  // stores index of previous 1
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(prev != -1 && i - prev - 1 < k) {
                    return false;
                }
                prev = i;
            }
        }
        
        return true;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    bool result = s.kLengthApart(nums, k);

    if(result) 
        cout << "true\n";
    else 
        cout << "false\n";

    return 0;
}
