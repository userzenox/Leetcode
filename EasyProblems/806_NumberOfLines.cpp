#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans;
        int sum = 0;
        int count = 1;
        for (int i = 0; i < s.size(); i++) {
            int w = widths[s[i] - 'a'];
            if (sum + w > 100) {
                count++;
                sum = w;
            } 
            else {
                sum += w;
            }
        }
        ans.push_back(count);
        ans.push_back(sum);
        return ans;
    }
};

int main() {
    // Example widths: all letters have width 10
    vector<int> widths(26, 10);

    // Example string
    string s = "abcdefghijklmnopqrstuvwxyz";

    // Call the function
    Solution sol;
    vector<int> result = sol.numberOfLines(widths, s);

    // Print the result
    cout << "Number of lines: " << result[0] << endl;
    cout << "Width of last line: " << result[1] << endl;

    return 0;
}
