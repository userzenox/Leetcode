#include <iostream>
#include <stack>

using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with iterative approach
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        int sum = 0;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();

            // Check if left child is a leaf
            if (current->left) {
                if (isLeaf(current->left)) {
                    sum += current->left->val;
                } else {
                    st.push(current->left);
                }
            }

            // Always push the right child if it exists
            if (current->right) {
                st.push(current->right);
            }
        }

        return sum;
    }
};

// Test case in main
int main() {
    /*
        Constructed binary tree:
              10
             /  \
            5    15
           / \     \
          2   6     20
               \
                8
        Left leaf: 2
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);         // Left leaf ✅
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(8); // Right leaf ❌

    root->right->right = new TreeNode(20);      // Right leaf ❌

    Solution sol;
    int result = sol.sumOfLeftLeaves(root);

    cout << "Sum of left leaves: " << result << endl; // Expected: 2

    // Cleanup (to avoid memory leaks)
    delete root->left->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
