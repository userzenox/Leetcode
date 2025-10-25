#include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int start = 1;

        int i = 1;
        while (i <= n) {
            int temp = start;
            int cnt = 1;
            while (i <= n && cnt <= 7) {
                sum += temp;
                temp++;
                i++;
                cnt++;
            }
            start++;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter the number of days: ";
    cin >> n;

    int result = sol.totalMoney(n);
    cout << "Total money after " << n << " days is: " << result << endl;

    return 0;
}
