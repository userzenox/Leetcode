#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Your Solution class
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;

        ListNode* temp = head;
        int count = 0;

        // Count total number of nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // If we need to remove the head node
        if (n == count) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Go to the node just before the one to be deleted
        int steps = count - n;
        temp = head;
        for (int i = 1; i < steps; i++) {
            temp = temp->next;
        }

        // Delete the node
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};

// Helper to create a linked list from a vector
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

// Helper to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to free memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example: remove 2nd node from end in list [1, 2, 3, 4, 5]
    vector<int> values = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "After removing " << n << "th node from end: ";
    printList(head);

    deleteList(head);

    return 0;
}
