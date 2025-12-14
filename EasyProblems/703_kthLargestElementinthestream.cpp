#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> mh;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int x : nums) {
            mh.push(x);
            if (mh.size() > this->k) {
                mh.pop();
            }
        }
    }
    
    int add(int val) {
        mh.push(val);
        if (mh.size() > k) {
            mh.pop();
        }
        return mh.top();
    }
};

int main() {
    // Example test case
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};

    KthLargest obj(k, nums);

    cout << obj.add(3) << endl;   // 4
    cout << obj.add(5) << endl;   // 5
    cout << obj.add(10) << endl;  // 5
    cout << obj.add(9) << endl;   // 8
    cout << obj.add(4) << endl;   // 8

    return 0;
}
