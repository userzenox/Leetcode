#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long sum = 0;
        for(long long b : batteries)
            sum += b;

        long long s = 0, e = sum / n, ans = 0;

        while(s <= e){
            long long mid = s + (e - s) / 2;

            long long total = 0;
            for(long long b : batteries)
                total += min(b, mid);

            if(total >= mid * n){
                ans = mid;
                s = mid + 1;  // try for longer time
            } else {
                e = mid - 1;  // reduce time
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of computers: ";
    cin >> n;

    int m;
    cout << "Enter number of batteries: ";
    cin >> m;

    vector<int> batteries(m);
    cout << "Enter battery capacities: ";
    for(int i = 0; i < m; i++) {
        cin >> batteries[i];
    }

    long long result = sol.maxRunTime(n, batteries);
    cout << "\nMaximum running time for all computers: " << result << " minutes\n";

    return 0;
}
