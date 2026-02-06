#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            
            if (nums[i] == 0) {
                result[i] = nums[i];
            } 
            else {
                // Safe circular index handling
                int step = ((i + nums[i]) % n + n) % n;
                result[i] = nums[step];
            }
        }
        
        return result;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.constructTransformedArray(nums);

    cout << "Transformed Array: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
