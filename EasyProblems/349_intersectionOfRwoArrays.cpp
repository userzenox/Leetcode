#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for(int num : nums2) {
            if(set1.count(num)) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution solution;

    // Example inputs
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    // Call the intersection method
    vector<int> result = solution.intersection(nums1, nums2);

    // Print result
    cout << "Intersection: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
