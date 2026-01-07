#include <iostream>
#include <queue>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int level = 0;
        int maxi = INT_MIN;

        if (!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            level++;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (sum > maxi) {
                maxi = sum;
                ans = level;
            }
        }

        return ans;
    }
};

int main() {
    /*
        Tree:
              1
             / \
            7   0
           / \
          7  -8

        Level sums:
        Level 1 → 1
        Level 2 → 7
        Level 3 → -1
        Answer → 2
    */

    TreeNode* root = new TreeNode(
        1,
        new TreeNode(7, new TreeNode(7), new TreeNode(-8)),
        new TreeNode(0)
    );

    Solution sol;
    cout << "Level with maximum sum: " << sol.maxLevelSum(root) << endl;

    return 0;
}
