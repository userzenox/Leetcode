#include <iostream>
#include <string>
#include <algorithm> // for max(), min()
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int max_value = num;
        int min_value = num;

        // Maximize: Replace one digit with '9'
        for (char d = '0'; d <= '9'; d++) {
            string temp = s;
            for (char &c : temp) {
                if (c == d)
                    c = '9';
            }
            max_value = max(max_value, stoi(temp));
        }

        // Minimize: Replace one digit with '0'
        for (char d = '0'; d <= '9'; d++) {
            string temp = s;
            for (char &c : temp) {
                if (c == d)
                    c = '0';
            }
            min_value = min(min_value, stoi(temp));
        }

        return max_value - min_value;
    }
};

int main() {
    Solution sol;

    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = sol.minMaxDifference(num);
    cout << "Maximum Difference by Remapping: " << result << endl;

    return 0;
}
