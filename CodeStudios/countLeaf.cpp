#include <iostream>
using namespace std;

/**********************************************************

    Binary Tree Node class structure:

**********************************************************/
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

// Function to count leaf nodes
int leafcount(BinaryTreeNode<int> *root, int &count) {
    if (root == NULL) {
        return count;
    }

    if (root->left == NULL && root->right == NULL) {
        count++;
    }

    leafcount(root->left, count);
    leafcount(root->right, count);

    return count;
}

int noOfLeafNodes(BinaryTreeNode<int> *root) {
    int count = 0;
    return leafcount(root, count);
}

// Driver code
int main() {
    // Manually creating the following tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //
    // Leaf nodes: 4, 5, 3 => Total = 3

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    cout << "Number of leaf nodes: " << noOfLeafNodes(root) << endl;

    // Cleanup memory
    delete root;

    return 0;
}
