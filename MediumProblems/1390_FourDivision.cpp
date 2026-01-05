#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findsum(int n) {
        int sum = 0;
        int count = 0;

        for (int f = 1; f * f <= n; f++) {
            if (n % f == 0) {
                int other = n / f;

                if (f == other) {
                    count += 1;
                    sum += f;
                } else {
                    count += 2;
                    sum += f + other;
                }

                if (count > 4) {
                    return 0;
                }
            }
        }

        return (count == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (int n : nums) {
            result += findsum(n);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {21, 4, 7};
    // 21 → divisors: 1, 3, 7, 21 → sum = 32
    // 4  → divisors: 1, 2, 4 → ignored
    // 7  → divisors: 1, 7 → ignored

    int result = sol.sumFourDivisors(nums);
    cout << "Sum of numbers with exactly four divisors: " << result << endl;

    return 0;
}
