#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
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

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

private:
    void dfs(Node* node, vector<int>& result) {
        if (node == nullptr) return;

        result.push_back(node->val); // Visit current node
        for (Node* child : node->children) {
            dfs(child, result); // Visit each child
        }
    }
};

// Utility function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Construct the N-ary tree:
    //         1
    //       / | \
    //      3  2  4
    //     / \
    //    5   6

    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    vector<Node*> children3 = {node5, node6};
    Node* node3 = new Node(3, children3);
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    vector<Node*> children1 = {node3, node2, node4};
    Node* root = new Node(1, children1);

    Solution sol;
    vector<int> result = sol.preorder(root);

    cout << "Preorder traversal: ";
    printVector(result);

    // Clean up memory
    delete node5;
    delete node6;
    delete node3;
    delete node2;
    delete node4;
    delete root;

    return 0;
}
