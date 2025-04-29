#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class as provided
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            return;
        }

        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    // Let's say we want to delete the node with value 3
    ListNode* nodeToDelete = head->next->next;  // 3rd node (value = 3)

    Solution sol;
    sol.deleteNode(nodeToDelete);

    cout << "List after deleting node with value 3: ";
    printList(head);

    return 0;
}
