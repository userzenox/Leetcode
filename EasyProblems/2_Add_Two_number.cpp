#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void insertAtTail(ListNode*& head, ListNode*& tail, int digit) {
        ListNode* temp = new ListNode(digit);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            carry = sum / 10;

            insertAtTail(ansHead, ansTail, digit);

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return ansHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2);
    }
};

// Helper to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create a linked list from a vector
ListNode* createList(const vector<int>& digits) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int d : digits) {
        ListNode* temp = new ListNode(d);
        if (!head) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

// Free memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Example input: 342 + 465 = 807
    vector<int> num1 = {2, 4, 3}; // represents 342
    vector<int> num2 = {5, 6, 4}; // represents 465

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    cout << "Input 1: ";
    printList(l1);
    cout << "Input 2: ";
    printList(l2);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result:  ";
    printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    return 0;
}
