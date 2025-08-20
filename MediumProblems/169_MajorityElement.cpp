#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int number = 0;
        for (auto num : nums) {
            if (count == 0) {
                number = num;
            }
            count += (num == number) ? 1 : -1;
        }
        return number;
    }
};

int main() {
    Solution sol;

    // Example input vector
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(nums);
    cout << "Majority Element is: " << result << endl;

    return 0;
}
