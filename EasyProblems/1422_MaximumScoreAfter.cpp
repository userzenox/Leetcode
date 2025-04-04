#include <iostream>
#include <string>
#include <algorithm> // For std::max

class Solution {
public:
    int maxScore(std::string s) {
        int n = s.size();
        int ones = 0, zeros = 0, maxs = 0;

        // Count total number of '1's in the string
        for (int i = 0; i < n; i++) {    
            if (s[i] == '1') {
                ones++;
            }
        }

        // Iterate up to n - 1 to ensure non-empty right substring
        for (int i = 0; i < n - 1; i++) {    
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }
            maxs = std::max(maxs, zeros + ones);
        }

        return maxs;
    }
};

int main() {
    Solution solution;
    std::string s = "011101"; // Example input
    int result = solution.maxScore(s);
    std::cout << "The maximum score after splitting the string is: " << result << std::endl;
    return 0;
}
