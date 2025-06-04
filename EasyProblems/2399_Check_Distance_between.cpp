// file: check_distances.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> f(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            if (f[index] == -1) {
                f[index] = i;
            } else {
                if (i - f[index] - 1 != distance[index]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    string s = "abaccb";
    vector<int> distance(26, 0);
    distance[0] = 1; // distance between two 'a's is 1
    distance[1] = 2; // distance between two 'b's is 2
    distance[2] = 0; // distance between two 'c's is 0

    Solution sol;
    bool result = sol.checkDistances(s, distance);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
