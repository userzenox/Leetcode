#include <bits/stdc++.h>
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
    TreeNode(int x, TreeNode *l, TreeNode *r)
        : val(x), left(l), right(r) {}
};

class Solution {
public:
    const long long M = 1e9 + 7;
    long long maxp = 0;
    long long totalsum = 0;

    long long tsum(TreeNode* root) {
        if (!root) return 0;

        long long sum = root->val
                      + tsum(root->left)
                      + tsum(root->right);

        maxp = max(maxp, sum * (totalsum - sum));
        return sum;
    }

    int maxProduct(TreeNode* root) {
        totalsum = tsum(root);  // total tree sum
        maxp = 0;
        tsum(root);             // compute best split
        return maxp % M;
    }
};

int main() {
    /*
        Example:
              1
             / \
            2   3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    cout << sol.maxProduct(root) << endl;

    return 0;
}
