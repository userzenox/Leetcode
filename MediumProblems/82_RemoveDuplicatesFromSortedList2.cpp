#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode temp(0, head);
        ListNode* prev = &temp;
        ListNode* curr = head;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return temp.next;
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Clean up allocated memory
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Create linked list from array
    ListNode* head = createList(arr, n);

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* newHead = sol.deleteDuplicates(head);

    std::cout << "After removing duplicates: ";
    printList(newHead);

    // Clean up memory
    deleteList(newHead);

    return 0;
}
