#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int getVal(char c) {
        char arr1[7] = {'I','V','X','L','C','D','M'};
        int arr2[7] = {1, 5, 10, 50, 100, 500, 1000};
        for(int i = 0; i < 7; i++) {
            if(arr1[i] == c) return arr2[i];
        }
        return 0; 
    }

    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            int curr = getVal(s[i]);
            int next = (i + 1 < s.size()) ? getVal(s[i + 1]) : 0;

            if(curr < next) {
                sum += (next - curr);
                i++; 
            } else {
                sum += curr;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    string roman;
    
    cout << "Enter a Roman numeral: ";
    cin >> roman;

    int result = sol.romanToInt(roman);
    cout << "Integer value: " << result << endl;

    return 0;
}
