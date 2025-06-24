#include <iostream>
#include <climits>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class (same as you wrote)
class Solution {
public:
    void second_min(TreeNode* root, int mini, long &secondmin){
        if (!root) return;

        if (root->val > mini && root->val < secondmin) {
            secondmin = root->val;
        }

        second_min(root->left, mini, secondmin);
        second_min(root->right, mini, secondmin);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        int mini = root->val;
        long secondmin = LONG_MAX;

        second_min(root, mini, secondmin);

        return (secondmin == LONG_MAX) ? -1 : (int)secondmin;
    }
};

// Main function
int main() {
    // Constructing the tree:
    //         2
    //        / \
    //       2   5
    //          / \
    //         5   7

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5, new TreeNode(5), new TreeNode(7));

    Solution sol;
    int result = sol.findSecondMinimumValue(root);
    cout << "Second minimum value: " << result << endl;

    // Freeing memory (optional here)
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
