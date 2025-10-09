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
    // Helper function to build BST from sorted array
    TreeNode* buildBST(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr; // base case

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, start, mid - 1);
        root->right = buildBST(nums, mid + 1, end);

        return root;
    }

    // Main function to call
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};

// Helper function to print inorder traversal of BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper function to print level order traversal (for better visualization)
void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "\n";
    }
}

int main() {
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << "\n\nLevel Order Traversal of BST:\n";
    levelOrder(root);

    return 0;
}
