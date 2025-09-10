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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool find(TreeNode* root, int k, set<int> &st) {
        if (root == NULL) return false;

        // Check if complement exists in set
        if (st.count(k - root->val)) return true;

        // Insert current node value
        st.insert(root->val);

        // Recurse into left and right subtrees
        return find(root->left, k, st) || find(root->right, k, st);
    }

    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        return find(root, k, st);
    }
};

// Helper function to build a simple BST for testing
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    /*
        Example BST:
              5
             / \
            3   6
           / \    \
          2   4    7
    */
    TreeNode* root = nullptr;
    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 7);

    Solution sol;
    int target = 9;

    if (sol.findTarget(root, target))
        cout << "Pair exists!" << endl;
    else
        cout << "No pair found." << endl;

    return 0;
}
