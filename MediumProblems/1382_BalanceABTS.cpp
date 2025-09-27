#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> vals;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left = build(l, mid - 1);
        node->right = build(mid + 1, r);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vals.clear();
        inorder(root);
        return build(0, vals.size() - 1);
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Create an unbalanced BST
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "Original BST Inorder: ";
    printInorder(root);
    cout << endl;

    Solution sol;
    TreeNode* balancedRoot = sol.balanceBST(root);

    cout << "Balanced BST Inorder: ";
    printInorder(balancedRoot);
    cout << endl;

    return 0;
}
