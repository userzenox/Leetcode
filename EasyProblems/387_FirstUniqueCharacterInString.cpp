#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};

        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            arr[c]++;
        }

        for(int i = 0; i < s.size(); i++){
            if(arr[s[i] - 'a'] == 1){
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string test1 = "leetcode";
    string test2 = "loveleetcode";
    string test3 = "aabb";

    cout << sol.firstUniqChar(test1) << endl;     // Output: 0
    cout << sol.firstUniqChar(test2) << endl;     // Output: 2
    cout << sol.firstUniqChar(test3) << endl;     // Output: -1

    return 0;
}
