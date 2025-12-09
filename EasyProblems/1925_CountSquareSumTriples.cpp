#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int count = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int s = i*i + j*j;
                int r = sqrt(s);

                if(r * r == s && r <= n) {
                    count += 2; // (i, j, r) and (j, i, r)
                }
            }
        }
        return count;
    }
};

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    Solution obj;
    int result = obj.countTriples(n);

    cout << "Number of Pythagorean square sum triples: " << result << endl;

    return 0;
}
