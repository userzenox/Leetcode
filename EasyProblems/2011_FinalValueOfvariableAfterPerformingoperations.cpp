#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (const auto& op : operations) {
            result += (op[1] == '+') ? 1 : -1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> operations1 = {"--X","X++","X++"};
    cout << "Test Case 1 Output: " << solution.finalValueAfterOperations(operations1) << endl; // 1

    vector<string> operations2 = {"++X","++X","X++"};
    cout << "Test Case 2 Output: " << solution.finalValueAfterOperations(operations2) << endl; // 3

    vector<string> operations3 = {"X++","++X","--X","X--"};
    cout << "Test Case 3 Output: " << solution.finalValueAfterOperations(operations3) << endl; // 0

    return 0;
}
