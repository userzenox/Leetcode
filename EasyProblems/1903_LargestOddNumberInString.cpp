
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution solution;
    
    string input1 = "123456";
    cout << "Largest odd number in \"" << input1 << "\" is: \"" 
         << solution.largestOddNumber(input1) << "\"" << endl;
    
    string input2 = "2468";
    cout << "Largest odd number in \"" << input2 << "\" is: \"" 
         << solution.largestOddNumber(input2) << "\"" << endl;
    
    string input3 = "13579";
    cout << "Largest odd number in \"" << input3 << "\" is: \"" 
         << solution.largestOddNumber(input3) << "\"" << endl;

    return 0;
}
