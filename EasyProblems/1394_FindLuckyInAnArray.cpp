#include <iostream>
#include <vector>
#include <unordered_map>
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
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = sol.findLucky(arr);

    cout << "The largest lucky integer is: " << result << endl;

    return 0;
}
