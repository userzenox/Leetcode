#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long totalCount = 1;
        long long count = 1;

        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                count++;
            } else {
                count = 1;
            }
            totalCount += count;
        }

        return totalCount;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices:\n";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution sol;
    long long result = sol.getDescentPeriods(prices);

    cout << "Number of smooth descent periods: " << result << endl;

    return 0;
}
