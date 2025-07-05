#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num : arr) {
            count[num]++;
        }

        int output = -1;
        for (auto& [num, freq] : count) {
            if (num == freq) {
                output = max(output, num);
            }
        }

        return output;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {2, 2, 3, 4};
    int result = sol.findLucky(arr);

    cout << "Lucky integer: " << result << endl;

    return 0;
}
