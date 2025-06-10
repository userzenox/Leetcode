#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> arr(26, 0);

        // Count frequency of each character
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            arr[ch]++;
        }

        int oddfrequency = -1;
        int evenfrequency = INT_MAX;
        bool hasEven = false; // Flag to check presence of even frequency

        // Find max odd frequency and min even frequency
        for (int i = 0; i < 26; i++) {
            int count = arr[i];

            if (count != 0 && count % 2 == 0) {
                evenfrequency = min(evenfrequency, count);
                hasEven = true;
            } else if (count != 0) {
                oddfrequency = max(oddfrequency, count);
            }
        }

        // Handle case where no even frequencies exist
        return hasEven ? (oddfrequency - evenfrequency) : oddfrequency;
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter a string: ";
    cin >> input;

    int result = sol.maxDifference(input);
    cout << "Max Difference: " << result << endl;

    return 0;
}