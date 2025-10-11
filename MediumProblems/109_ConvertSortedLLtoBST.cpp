#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* Solution class */
class Solution {
public:
    // Count number of nodes in linked list
    int count(ListNode* head) {
        int n = 0;
        while (head != nullptr) {
            n++;
            head = head->next;
        }
        return n;
    }

    // Convert sorted LL to BST (helper function)
    TreeNode* sortLLtoBST(ListNode*& head, int n) {
        if (n <= 0 || head == nullptr)
            return nullptr;

        // Build left subtree
        TreeNode* left = sortLLtoBST(head, n / 2);

        // Create root node
        TreeNode* root = new TreeNode(head->val);
        root->left = left;

        // Move linked list head forward
        head = head->next;

        // Build right subtree
        root->right = sortLLtoBST(head, n - 1 - n / 2);

        return root;
    }

    // Main function to convert sorted list to BST
    TreeNode* sortedListToBST(ListNode* head) {
        int n = count(head);
        return sortLLtoBST(head, n);
    }
};

/* Utility Functions */
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper to create linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

/* Main function */
int main() {
    vector<int> arr = {-10, -3, 0, 5, 9}; // Sorted linked list values

    // Create linked list
    ListNode* head = createList(arr);

    // Convert to BST
    Solution sol;
    TreeNode* root = sol.sortedListToBST(head);

    // Print inorder traversal of BST (should match input)
    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
