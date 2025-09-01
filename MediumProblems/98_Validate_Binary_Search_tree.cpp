#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    bool isBST(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;

        if (root->val <= minVal || root->val >= maxVal) return false;

        return isBST(root->left, minVal, root->val) &&
               isBST(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};

// Driver code
int main() {
    /*
        Constructing this tree:
                5
               / \
              1   7
                 / \
                6   8
        This is a valid BST
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;
    if (sol.isValidBST(root))
        cout << "The tree is a valid BST" << endl;
    else
        cout << "The tree is NOT a valid BST" << endl;

    /*
        Now let’s make it invalid:
        Change left child of root->right from 6 to 4
    */
    root->right->left->val = 4;
    if (sol.isValidBST(root))
        cout << "The tree is a valid BST" << endl;
    else
        cout << "The tree is NOT a valid BST" << endl;

    return 0;
}
