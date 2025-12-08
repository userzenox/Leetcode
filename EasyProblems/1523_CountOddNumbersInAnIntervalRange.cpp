#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
    
        if (low % 2 != 0 || high % 2 != 0) {
            return (high - low) / 2 + 1;
        }
        
        else if (low % 2 == 0 && high % 2 == 0) {
            return (high - low) / 2;
        }

        return 0;
    }
};

int main() {
    int low, high;
    cout << "Enter low value: ";
    cin >> low;
    cout << "Enter high value: ";
    cin >> high;

    Solution obj;
    int result = obj.countOdds(low, high);

    cout << "Number of odd numbers between " << low << " and " << high << " is: " << result << endl;

    return 0;
}
