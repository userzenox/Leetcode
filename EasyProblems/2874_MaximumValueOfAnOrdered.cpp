#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxs = 0;  
        
        for(int i = 0; i < n; i++) {          
            for(int j = i + 1; j < n; j++) {  
                for(int k = j + 1; k < n; k++) { 
                    long long sum = (long long)(nums[i] - nums[j]) * nums[k];
                    maxs = max(maxs, sum);
                }
            }
        } 

        return maxs;
    }
};

int main() {
    vector<int> nums = {2, 3, 1}; // Test case
    
    Solution sol;
    long long result = sol.maximumTripletValue(nums);
    
    cout << "Output: " << result << endl; // Expected Output: 0
    
    return 0;
}
