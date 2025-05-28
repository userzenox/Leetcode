#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node definition
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Solution class
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

private:
    void dfs(Node* node, vector<int>& result) {
        if (!node) return;

        for (int i = 0; i < node->children.size(); ++i) {
            dfs(node->children[i], result);
        }

        result.push_back(node->val);
    }
};

// Main function
int main() {
    // Creating the tree:
    //        1
    //      / | \
    //     3  2  4
    //    / \
    //   5   6

    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node3, node2, node4});

    Solution sol;
    vector<int> result = sol.postorder(root);

    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up (to avoid memory leak)
    delete node5;
    delete node6;
    delete node3;
    delete node2;
    delete node4;
    delete root;

    return 0;
}
