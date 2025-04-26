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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        ListNode* temp = head;
        int length = 1;

        while (temp->next != NULL) {
            temp = temp->next;
            length++;
        }

        temp->next = head; // Make circular

        k = k % length;
        if (k == 0) {
            temp->next = NULL; 
            return head;
        }

        int size = length - k;
        temp = head;
        for (int i = 1; i < size; i++) {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* rotated = sol.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(rotated);

    return 0;
}
