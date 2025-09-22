#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxf = 0;
        int arr[101] = {0};  
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
            maxf = max(arr[nums[i]], maxf);
        }

        for(int i = 0; i < 101; i++) {
            if(arr[i] == maxf) {
                ans += arr[i];  
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 1, 2};
    int result = sol.maxFrequencyElements(nums);
    cout << "Max frequency elements count: " << result << endl;
    return 0;
}
