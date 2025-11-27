#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        class node {
        public:
            int data;
            int row;
            int col;

            node(int d, int r, int c) {
                data = d;
                row = r;
                col = c;
            }
        };

        class cmp {
        public:
            bool operator()(node* a, node* b) {
                return a->data > b->data;  // Min Heap
            }
        };

        priority_queue<node*, vector<node*>, cmp> pq;

        int k = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;

        // Push first element of each list into heap
        for (int i = 0; i < k; i++) {
            int val = nums[i][0];
            pq.push(new node(val, i, 0));

            mini = min(mini, val);
            maxi = max(maxi, val);
        }

        int start = mini, end = maxi;

        // Process heap
        while (!pq.empty()) {

            node* temp = pq.top();
            pq.pop();

            mini = temp->data;

            // Update range if smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // If next element exists in same row
            if (temp->col + 1 < nums[temp->row].size()) {
                int nextVal = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextVal);
                pq.push(new node(nextVal, temp->row, temp->col + 1));
            } else {
                break; // One list finished → no valid full range further
            }
        }

        return {start, end};
    }
};

int main() {
    Solution obj;

    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = obj.smallestRange(nums);

    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
