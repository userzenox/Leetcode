#include <iostream>
#include <utility>  // for std::pair
#include <algorithm> // for std::max
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
    pair<int, int> diameter(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};  // {diameter, height}
        }

        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        int dia = max({op1, op2, op3});
        int height = max(left.second, right.second) + 1;

        return {dia, height};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};

int main() {
    /*
       Sample Tree:
           1
          / \
         2   3
        / \
       4   5

       Diameter = 3 (path = 4 -> 2 -> 1 -> 3)
    */

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << diameter << endl;

    // Free allocated memory
    delete node4;
    delete node5;
    delete node2;
    delete node3;
    delete root;

    return 0;
}
