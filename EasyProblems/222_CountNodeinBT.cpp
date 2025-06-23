#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void countNodesHelper(TreeNode* root, int &cnt) {
        if (root == nullptr) return;
        cnt++; // Count current node
        countNodesHelper(root->left, cnt);
        countNodesHelper(root->right, cnt);
    }

    int countNodes(TreeNode* root) {
        int cnt = 0;
        countNodesHelper(root, cnt);
        return cnt;
    }
};

int main() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int result = sol.countNodes(root);
    cout << "Total nodes in the tree: " << result << endl;

    // Clean up memory (important in real use!)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
