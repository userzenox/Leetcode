#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int size = heights.size();
        vector<int> ans = heights;
        int count = 0;

        sort(ans.begin(), ans.end());

        for (int i = 0; i < size; i++) {
            if (heights[i] != ans[i]) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {1, 1, 4, 2, 1, 3};

    int result = sol.heightChecker(heights);
    cout << "Number of students not in correct position: " << result << endl;

    return 0;
}
