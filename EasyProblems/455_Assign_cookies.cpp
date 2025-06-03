#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        int count = 0;
        
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i++;
                j++;
                count++;
            } else {
                j++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> g = {1, 2, 3}; // Greed factors
    vector<int> s = {1, 1};    // Cookie sizes

    Solution sol;
    int result = sol.findContentChildren(g, s);
    cout << "Maximum number of content children: " << result << endl;

    return 0;
}
