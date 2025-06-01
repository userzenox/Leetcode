#include <iostream>
#include <cmath>     // for abs
#include <algorithm> // for max
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
    pair<bool, int> checkbalance(TreeNode* root) {
        if (root == nullptr) {
            return {true, 0}; // {isBalanced, height}
        }

        pair<bool, int> left = checkbalance(root->left);
        pair<bool, int> right = checkbalance(root->right);

        bool leftBalanced = left.first;
        bool rightBalanced = right.first;
        bool heightDiffOk = abs(left.second - right.second) <= 1;

        int height = max(left.second, right.second) + 1;
        bool balanced = leftBalanced && rightBalanced && heightDiffOk;

        return {balanced, height};
    }

    bool isBalanced(TreeNode* root) {
        return checkbalance(root).first;
    }
};

int main() {
    /*
        Balanced Tree Example:
               1
              / \
             2   3
            /
           4

        This is a balanced tree.
    */

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node4, nullptr);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);

    Solution sol;
    bool balanced = sol.isBalanced(root);

    cout << "Is the binary tree balanced? " << (balanced ? "Yes" : "No") << endl;

    // Free allocated memory
    delete node4;
    delete node2;
    delete node3;
    delete root;

    return 0;
}
