#include <iostream>
using namespace std;

/** Definition for a binary tree node. */
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
    bool checkTree(TreeNode* root) {
        if (!root || !root->left || !root->right) return false;
        return root->val == (root->left->val + root->right->val);
    }
};

int main() {
    // Build the tree:
    //     10
    //    /  \
    //   4    6

    TreeNode* leftChild = new TreeNode(4);
    TreeNode* rightChild = new TreeNode(6);
    TreeNode* root = new TreeNode(10, leftChild, rightChild);

    Solution solution;
    bool result = solution.checkTree(root);

    cout << (result ? "True" : "False") << endl;

    // Clean up memory
    delete leftChild;
    delete rightChild;
    delete root;

    return 0;
}
