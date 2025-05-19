
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];

        // Check for triangle validity using triangle inequality
        if (a + b <= c || b + c <= a || a + c <= b) {
            return "none";
        }

        // Classify the triangle
        if (a == b && b == c) {
            return "equilateral";
        } else if (a == b || b == c || a == c) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 3, 3},   // equilateral
        {3, 4, 5},   // scalene
        {5, 5, 8},   // isosceles
        {1, 2, 3},   // none
        {10, 10, 10}, // equilateral
        {2, 2, 5}    // none (violates triangle inequality)
    };

    for (auto& test : testCases) {
        cout << "Sides: " << test[0] << ", " << test[1] << ", " << test[2]
             << " -> Type: " << sol.triangleType(test) << endl;
    }

    return 0;
}
