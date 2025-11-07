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
    TreeNode* curr;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        root->left = NULL;
        curr->right = root;
        curr = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        curr = dummy;
        inorder(root);
        return dummy->right;
    }
};

// Helper function to insert nodes into a Binary Search Tree (for testing)
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Helper function to print tree in-order
void printRightSkewed(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
}

int main() {
    // Example tree:
    //       5
    //      / \
    //     3   6
    //    / \   \
    //   2   4   8
    //  /       / \
    // 1       7   9

    TreeNode* root = nullptr;
    vector<int> values = {5, 3, 6, 2, 4, 8, 1, 7, 9};

    for (int v : values)
        root = insertBST(root, v);

    Solution sol;
    TreeNode* newRoot = sol.increasingBST(root);

    cout << "Increasing Order Search Tree (Right Skewed): ";
    printRightSkewed(newRoot);
    cout << endl;

    return 0;
}
