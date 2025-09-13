#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxVowelsAndConsonants(const string& s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        string vowels = "aeiou";
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        for (auto& p : freq) {
            char ch = p.first;
            int count = p.second;
            if (vowels.find(ch) != string::npos) {
                maxVowelFreq = max(maxVowelFreq, count);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, count);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};

int main() {
    Solution solution;

    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = solution.maxVowelsAndConsonants(s);
    cout << "Sum of most frequent vowel and consonant count is: " << result << endl;

    return 0;
}
