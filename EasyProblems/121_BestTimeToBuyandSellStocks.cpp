#include <iostream>
#include <vector>
#include <algorithm> // for max and min functions

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = prices[0];
        int cost = 0;

        for(int i = 0; i < prices.size(); i++) {
            cost = prices[i] - mini;
            maxi = max(cost, maxi);
            mini = min(mini, prices[i]);
        }       
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};  // example input
    int profit = sol.maxProfit(prices);
    cout << "Maximum profit: " << profit << endl;
    return 0;
}
