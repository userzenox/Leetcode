#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      
        vector<int> ans;
        ans.push_back(0);     // you added this, so keeping it

        int s = 0;
        for(int i = 0; i < gain.size(); i++){
            s += gain[i];
            gain[i] = s;      // converting gain[] into prefix altitudes
        }

        int maxi = 0;
        for(auto x : gain){
            maxi = max(maxi, x);
        }
       
        return maxi;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> gain(n);
    for(int i = 0; i < n; i++) {
        cin >> gain[i];
    }

    Solution obj;
    cout << obj.largestAltitude(gain);

    return 0;
}
