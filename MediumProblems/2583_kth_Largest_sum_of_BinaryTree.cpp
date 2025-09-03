#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void updateArr(TreeNode * &root, vector<long long>& arr, int level = 1) {
        if (root == NULL)
            return;
        arr[level - 1] += root->val;
        updateArr(root->left, arr, level + 1);
        updateArr(root->right, arr, level + 1);
    }
    int height(TreeNode * &root) {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int levels = height(root);
        if (levels < k)
            return -1;
        vector<long long> ans(levels, 0);
        updateArr(root, ans);

        bool isSorted = true;
        for (int i = 1; i < levels; i++) {
            if (ans[i] < ans[i - 1]) {
                isSorted = false;
                break;
            }
        }
        if (isSorted)
            return ans[levels - k];

        if (k == 1) {
            long long M = INT_MIN;
            for (int num : ans)
                M = max(M, (long long)num);
            return M;
        }
        else if (k == levels) {
            long long M = INT_MAX;
            for (int num : ans)
                M = min(M, (long long)num);
            return M;
        }

        sort(ans.begin(), ans.end());
        return ans[levels - k];
    }
};

int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    for (int k = 1; k <= 3; ++k) {
        cout << "The " << k << "-th largest level sum is: "
            << sol.kthLargestLevelSum(root, k) << endl;
    }

    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
