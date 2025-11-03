#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;
        for (int i = 1; i < (int)colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                // Add the minimum neededTime of adjacent balloons having the same color
                sum += min(neededTime[i], neededTime[i - 1]);
                // Keep the maximum neededTime for the next comparisons
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    string colors;
    int n;

    cout << "Enter the colors string: ";
    cin >> colors;

    cout << "Enter the number of balloons: ";
    cin >> n;

    vector<int> neededTime(n);
    cout << "Enter the needed times:\n";
    for (int i = 0; i < n; i++) {
        cin >> neededTime[i];
    }

    int result = solution.minCost(colors, neededTime);
    cout << "Minimum cost to make all balloons unique: " << result << endl;

    return 0;
}
