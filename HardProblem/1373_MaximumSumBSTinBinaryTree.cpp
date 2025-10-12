#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    struct Info {
        int mini;
        int maxi;
        bool isBST;
        int sum;
    };

    Info solve(TreeNode* root, int &ans) {
        // Base case: empty tree is a BST with sum = 0
        if (root == NULL) {
            return {INT_MAX, INT_MIN, true, 0};
        }

        Info left = solve(root->left, ans);
        Info right = solve(root->right, ans);

        Info current;

        current.mini = min(root->val, left.mini);
        current.maxi = max(root->val, right.maxi);
        current.sum = left.sum + right.sum + root->val;

        // Check if current subtree is a BST
        if (left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini)) {
            current.isBST = true;
            ans = max(ans, current.sum);
        } else {
            current.isBST = false;
        }

        return current;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

// Helper function to create a new node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Example main to test
int main() {
    /*
          1
         / \
        4   3
       / \
      2   4
    */

    TreeNode* root = newNode(1);
    root->left = newNode(4);
    root->right = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(4);

    Solution sol;
    cout << "Maximum Sum BST in the Tree: " << sol.maxSumBST(root) << endl;

    return 0;
}
