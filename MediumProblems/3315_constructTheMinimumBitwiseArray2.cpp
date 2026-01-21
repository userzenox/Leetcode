#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
 We need smallest x such that:
     (x | (x+1)) = n
 If impossible → -1

 Key cases:
 1) n == 2 → impossible
 2) n = (2^k - 1) → x = n >> 1
 3) General → find lowest zero bit j, construct:
        x = (n & ~((1<<j)-1)) | ((1<<j)-1)
*/

vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;
    ans.reserve(nums.size());

    for (int n : nums) {

        // Case 1: impossible
        if (n == 2) {
            ans.push_back(-1);
            continue;
        }

        // Case 2: n = all ones (2^k - 1)
        if ((n & (n + 1)) == 0) {
            ans.push_back(n >> 1);
            continue;
        }

        // Case 3: general case
        int j = 0;
        while (n & (1 << j)) j++;

        int x = (n & ~((1 << j) - 1)) | ((1 << j) - 1);
        ans.push_back(x);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = minBitwiseArray(nums);

    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i + 1 < n) cout << " ";
    }
    cout << "\n";

    return 0;
}
