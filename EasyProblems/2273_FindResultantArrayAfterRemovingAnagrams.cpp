
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkAnagrams(string s1, string s2) {
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);

        for (char c : s1) arr1[c - 'a']++;
        for (char c : s2) arr2[c - 'a']++;

        return arr1 == arr2;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            ans.push_back(words[i]);

            while (i + 1 < words.size() && checkAnagrams(words[i], words[i + 1])) {
                i++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};

    vector<string> result = sol.removeAnagrams(words);

    cout << "Resultant array after removing consecutive anagrams:\n";
    for (auto &word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}