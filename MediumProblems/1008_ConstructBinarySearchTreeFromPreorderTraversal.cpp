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
    TreeNode* buildBST(vector<int>& preorder, int maxi, int mini, int& i) {
        if (i >= preorder.size()) return NULL;

        if (preorder[i] < mini || preorder[i] > maxi)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        // build left subtree with updated upper bound
        root->left = buildBST(preorder, root->val, mini, i);
        // build right subtree with updated lower bound
        root->right = buildBST(preorder, maxi, root->val, i);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        int maxi = INT_MAX;
        int mini = INT_MIN;
        return buildBST(preorder, maxi, mini, i);
    }
};

// Helper function to print the BST in inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder Traversal of Constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
