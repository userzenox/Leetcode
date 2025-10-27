#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to count '1's in a string
    int countones(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '1') count++;
        }
        return count;
    }

    // Main function to calculate number of beams
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int prevCount = 0;  // number of '1's in previous non-empty row

        for (int i = 0; i < bank.size(); i++) {
            int currCount = countones(bank[i]);
            if (currCount == 0) continue;  // skip empty (no device) rows

            if (prevCount != 0) {
                totalBeams += prevCount * currCount;  // beam between consecutive non-empty rows
            }

            prevCount = currCount;  // update for next iteration
        }

        return totalBeams;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    cout << sol.numberOfBeams(bank) << endl;  // Output should be 8
    return 0;
}
