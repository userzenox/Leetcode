#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool boolcheck(TreeNode* root, int value) {
        if (root == nullptr) return true;
        if (root->val != value) return false;

        return boolcheck(root->left, value) && boolcheck(root->right, value);
    }

    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) return true;
        return boolcheck(root, root->val);
    }
};

int main() {
    // Create the tree [2, null, 1]
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(1);

    Solution sol;
    bool result = sol.isUnivalTree(root);

    cout << "Is the tree univalued? " << (result ? "Yes" : "No") << endl;

    // Free the memory
    delete root->right;
    delete root;

    return 0;
}
