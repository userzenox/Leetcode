#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0;
        int p2 = height.size() - 1;
        int area = 0;
        int maxarea = 0;
        int width = 0;
        while (p1 < p2) {
            if (height[p1] < height[p2]) {
                width = p2 - p1;
                area = height[p1] * width;
                p1++;
            } else {
                width = p2 - p1;
                area = height[p2] * width;
                p2--;
            }
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};  // Change values for other tests
    Solution sol;
    int result = sol.maxArea(height);
    cout << "Maximum water container area: " << result << endl;
    return 0;
}
