#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count frequency
        unordered_map<int,int> m;
        for (int x : nums) {
            m[x]++;
        }

        // store as {frequency, value}
        vector<pair<int,int>> v;
        for (auto &p : m) {
            v.push_back({p.second, p.first});
        }

        // sort by frequency descending
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // take top k values
        vector<int> res;
        for (int i = 0; i < k && i < (int)v.size(); i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};

int main() {
    int n, k;
    cin >> n >> k;                // n = size, k = top k
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
