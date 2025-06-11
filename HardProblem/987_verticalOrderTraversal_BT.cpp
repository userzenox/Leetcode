#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode* frontnode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].insert(frontnode->val);

            if (frontnode->left) {
                q.push(make_pair(frontnode->left, make_pair(hd - 1, lvl + 1)));
            }
            if (frontnode->right) {
                q.push(make_pair(frontnode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        for (auto i : nodes) {
            vector<int> column;
            for (auto j : i.second) {
                column.insert(column.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(column);
        }

        return ans;
    }
};

// Helper function to print the result
void printVerticalTraversal(const vector<vector<int>>& result) {
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    /*
        Constructed Binary Tree:
               3
              / \
             9   20
                /  \
               15   7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    cout << "Vertical Traversal of the Binary Tree:\n";
    printVerticalTraversal(result);

    // Free memory
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
