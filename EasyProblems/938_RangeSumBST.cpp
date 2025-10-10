#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        if (root->val < low) return rangeSumBST(root->right, low, high);
        if (root->val > high) return rangeSumBST(root->left, low, high);
        return root->val 
            + rangeSumBST(root->left, low, high) 
            + rangeSumBST(root->right, low, high);
    }
};

// Helper function to insert nodes in BST order
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) return new TreeNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Main function to test the solution
int main() {
    /* Example BST:
              10
             /  \
           5     15
          / \      \
         3   7     18
    */
    TreeNode* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 18);

    int low = 7, high = 15;
    Solution sol;
    cout << "Range Sum BST (" << low << ", " << high << "): "
         << sol.rangeSumBST(root, low, high) << endl;
    return 0;
}
