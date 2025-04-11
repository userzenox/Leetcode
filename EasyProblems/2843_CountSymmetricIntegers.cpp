#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int maincount = 0;
        for(int i = low; i <= high; i++) {
            string s = to_string(i);
            int count = s.size();
            
            if(count % 2 != 0) {
                continue; // skip odd-digit numbers
            }

            int sum1 = 0, sum2 = 0;
            for(int j = 0; j < count / 2; j++) {
                sum1 += s[j] - '0';
            }
            for(int j = count / 2; j < count; j++) {
                sum2 += s[j] - '0';
            }

            if(sum1 == sum2) {
                maincount++;
            }
        }

        return maincount;
    }
};

int main() {
    Solution sol;
    int low, high;

    cout << "Enter lower bound: ";
    cin >> low;
    cout << "Enter upper bound: ";
    cin >> high;

    int result = sol.countSymmetricIntegers(low, high);
    cout << "Count of symmetric integers: " << result << endl;

    return 0;
}
