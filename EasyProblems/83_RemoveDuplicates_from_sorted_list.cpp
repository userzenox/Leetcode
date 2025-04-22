#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            if (temp->val == temp->next->val) {
                ListNode* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;  // Free memory
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};

// Helper to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create a linked list from array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (int i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

// Helper to free memory
void deleteList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Example input: sorted list with duplicates
    vector<int> values = {1, 1, 2, 3, 3};
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    ListNode* updated = sol.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(updated);

    deleteList(updated); // Clean up memory

    return 0;
}
