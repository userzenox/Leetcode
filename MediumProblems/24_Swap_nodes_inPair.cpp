
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class with swapPairs method
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            prev->next = second;
            second->next = first;

            prev = first;
        }
        return dummy->next;
    }
};

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution sol;
    vector<int> vals = {1, 2, 3, 4}; // You can change this input to test other cases
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    ListNode* swapped = sol.swapPairs(head);

    cout << "Swapped list: ";
    printList(swapped);

    return 0;
}
