#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> v(128, {' ',0});  
               
        for(char c : s) {
            v[c].first = c;
            v[c].second++;
        }
        
        sort(v.begin(), v.end(), [](const pair<char,int>& p1, const pair<char,int>& p2) {
            return p1.second > p2.second;
        });
        
        string result;
        for(auto& p : v) {
            while(p.second > 0) {
                result += p.first;
                p.second--;
            }
        }
        return result;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution obj;
    string sortedString = obj.frequencySort(s);

    cout << "String sorted by character frequency: " << sortedString << endl;

    return 0;
}
