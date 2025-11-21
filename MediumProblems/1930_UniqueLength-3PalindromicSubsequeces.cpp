#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> index(26, {-1,-1});
        
        // store first and last occurrence
        for(int i=0; i<s.size(); i++){
            int idx = s[i] - 'a';
            if(index[idx].first == -1){
                index[idx].first = i;
            }
            index[idx].second = i;
        }

        int ans = 0;

        // check for each character as the outer one (c _ c)
        for(int i=0; i<26; i++){
            int f = index[i].first; 
            int l = index[i].second;

            if(f == -1 || l - f < 2) continue;

            unordered_set<char> st;

            for(int m = f + 1; m < l; m++){
                st.insert(s[m]);     // FIX: use character, not index
            }

            ans += st.size();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    cout << "Count = " << sol.countPalindromicSubsequence(s) << endl;

    return 0;
}
