#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefix;  

public:
    // Constructor to initialize the prefix sum array
    NumArray(vector<int>& nums) {
        prefix.push_back(0);  // start with 0 for easier calculation
        for (int num : nums) {
            prefix.push_back(prefix.back() + num);
        }
    }

    // Function to get the sum of elements between indices i and j (inclusive)
    int sumRange(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }
};

int main() {
    // Example input: nums = [-2, 0, 3, -5, 2, -1]
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj(nums);

    // Test cases
    cout << "sumRange(0, 2): " << obj.sumRange(0, 2) << endl; // 1
    cout << "sumRange(2, 5): " << obj.sumRange(2, 5) << endl; // -1
    cout << "sumRange(0, 5): " << obj.sumRange(0, 5) << endl; // -3

    return 0;
}
