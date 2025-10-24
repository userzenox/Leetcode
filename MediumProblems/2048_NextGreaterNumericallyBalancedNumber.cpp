// 2048. Next Greater Numerically Balanced Number
// Full working C++17 solution
#include <bits/stdc++.h>
using namespace std;

// Generate all numerically balanced numbers (as integers) whose length <= 10 (fits in 32-bit signed).
// A numerically balanced number is one where for every digit d that appears, it appears exactly d times.
// Example valid numbers: 1, 22, 122, 333 (3 appears 3 times), 11222 (1 once, 2 twice), etc.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    // We'll store all generated balanced numbers here (use long long to be safe during generation).
    vector<long long> balanced;

    // For each non-empty subset of digits 1..9:
    // There are 2^9 - 1 subsets.
    for (int mask = 1; mask < (1 << 9); ++mask) {
        // Build a multiset string where digit d appears d times if bit (d-1) in mask is set.
        string s;
        int totalDigits = 0;
        for (int d = 1; d <= 9; ++d) {
            if (mask & (1 << (d - 1))) {
                totalDigits += d;
                // If total digits exceed 10, skip - no 32-bit signed integer has more than 10 digits.
                if (totalDigits > 10) break;
            }
        }
        if (totalDigits == 0 || totalDigits > 10) continue;

        // Append each selected digit d exactly d times
        s.reserve(totalDigits);
        for (int d = 1; d <= 9; ++d) {
            if (mask & (1 << (d - 1))) {
                s.append(d, char('0' + d)); // append digit character d, d times
            }
        }

        // Now s contains characters like "11222" (unsorted). To generate unique permutations, sort then next_permutation.
        sort(s.begin(), s.end());
        // Use a set-local check to avoid duplicates across permutations (we'll insert final numbers into vector).
        do {
            // Convert permutation string to number (leading digit is never '0' because digits are 1..9)
            long long val = 0;
            for (char c : s) {
                val = val * 10 + (c - '0');
                // If val exceeds 32-bit signed max (2,147,483,647) we can stop for this permutation
                if (val > INT_MAX) break;
            }
            if (val <= INT_MAX) balanced.push_back(val);
        } while (next_permutation(s.begin(), s.end()));
    }

    // Remove duplicates (many different subsets/permutation sequences might produce same number)
    sort(balanced.begin(), balanced.end());
    balanced.erase(unique(balanced.begin(), balanced.end()), balanced.end());

    // Find smallest balanced number strictly greater than n
    auto it = upper_bound(balanced.begin(), balanced.end(), n);
    if (it == balanced.end()) {
        // Specification on LeetCode guarantees an answer exists within reasonable bound,
        // but in case, we print -1 or some sentinel. We'll print -1 here.
        cout << -1 << '\n';
    } else {
        cout << *it << '\n';
    }

    return 0;
}
