#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Your Solution class
class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans, int level) {
        if (root == nullptr) return;

        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

// Sample tree construction and function call
int main() {
    // Construct the following binary tree:
    //        1
    //       / \
    //      2   3
    //       \   \
    //        5   4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Free memory
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
