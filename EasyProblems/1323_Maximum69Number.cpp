#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        string s = to_string(num);
        
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;  // Only change the first '6'
            }
        }
        
        return stoi(s);
    }
};

int main() {
    Solution sol;
    
    int num;
    cout << "Enter a number made of digits 6 and 9 (e.g. 9669): ";
    cin >> num;
    
    int result = sol.maximum69Number(num);
    
    cout << "Maximum number after changing at most one 6 to 9: " << result << endl;
    
    return 0;
}
