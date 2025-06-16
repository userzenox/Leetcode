#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int max_value = num;
        int min_value = num;

        // Get max_value by replacing one digit with '9'
        for (char i = '0'; i <= '9'; i++) {
            string temp = s;
            for (int j = 0; j < temp.size(); j++) {
                if (temp[j] == i) {
                    temp[j] = '9';
                }
            }
            max_value = max(max_value, stoi(temp));
        }

        // Get min_value by replacing one digit with '0' or '1'
        for (char i = '0'; i <= '9'; i++) {
            string temp = s;
            bool leading = (temp[0] == i);
            for (char &c : temp) {
                if (c == i) {
                    if (leading) {
                        c = '1';
                    } else {
                        c = '0';
                    }
                }
            }

            if (temp[0] != '0') {
                min_value = min(min_value, stoi(temp));
            }
        }

        return max_value - min_value;
    }
};

int main() {
    Solution sol;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = sol.maxDiff(num);
    cout << "Maximum difference: " << result << endl;

    return 0;
}
