#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with preorderTraversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                ans.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            curr = curr->right;
        }
        return ans;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

int main() {
    // Creating a simple binary tree:
    //         1
    //          \
    //           2
    //          /
    //         3

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    printVector(result);

    // Cleanup memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
