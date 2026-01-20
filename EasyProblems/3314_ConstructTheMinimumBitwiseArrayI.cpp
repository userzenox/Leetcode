#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> B(n), A(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Construct A
    A[0] = B[0];
    for (int i = 1; i < n; i++) {
        A[i] = B[i] & B[i-1];
    }

    // Output A
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i+1 < n) cout << " ";
    }
    cout << "\n";

    return 0;
}
