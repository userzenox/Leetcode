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
    // Step 1: Convert BST to inorder (sorted array)
    void BSTtoinorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        BSTtoinorder(root->left, ans);
        ans.push_back(root->val);
        BSTtoinorder(root->right, ans);
    }

    // Step 2: Merge two sorted arrays
    vector<int> mergeSortedarray(vector<int>& ans1, vector<int>& ans2) {
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while (p1 < ans1.size() && p2 < ans2.size()) {
            if (ans1[p1] < ans2[p2]) ans.push_back(ans1[p1++]);
            else ans.push_back(ans2[p2++]);
        }
        while (p1 < ans1.size()) ans.push_back(ans1[p1++]);
        while (p2 < ans2.size()) ans.push_back(ans2[p2++]);
        return ans;
    }

    // Step 3: Convert sorted array back to balanced BST
    TreeNode* inordertoBST(vector<int>& ans, int s, int e) {
        if (s > e) return NULL;
        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = inordertoBST(ans, s, mid - 1);
        root->right = inordertoBST(ans, mid + 1, e);
        return root;
    }

    // Step 4: Main merge function
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1, ans2;
        BSTtoinorder(root1, ans1);
        BSTtoinorder(root2, ans2);
        vector<int> merged = mergeSortedarray(ans1, ans2);
        return inordertoBST(merged, 0, merged.size() - 1);
    }
};

// --- Utility functions for testing ---
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

void levelOrderPrint(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

// --- Main Function ---
int main() {
    Solution sol;

    // Create first BST
    TreeNode* root1 = nullptr;
    root1 = insertBST(root1, 2);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 4);

    // Create second BST
    TreeNode* root2 = nullptr;
    root2 = insertBST(root2, 1);
    root2 = insertBST(root2, 0);
    root2 = insertBST(root2, 3);

    cout << "BST 1 (Inorder): ";
    inorderPrint(root1);
    cout << "\nBST 2 (Inorder): ";
    inorderPrint(root2);
    cout << "\n\n";

    // Merge the two BSTs
    TreeNode* mergedRoot = sol.mergeTrees(root1, root2);

    cout << "Merged BST (Inorder): ";
    inorderPrint(mergedRoot);
    cout << "\n\nMerged BST (Level Order):\n";
    levelOrderPrint(mergedRoot);

    return 0;
}
