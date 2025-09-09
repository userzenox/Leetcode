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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

int main() {
    /*
        Example BST:
               6
              / \
             2   8
            / \ / \
           0  4 7  9
             / \
            3   5
    */
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution sol;

    TreeNode* p = root->left;     // Node with value 2
    TreeNode* q = root->left->right; // Node with value 4

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    // TODO: Add code to delete/free the tree if needed.

    return 0;
}
