
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

// Utility: create linked list from vector
ListNode* buildList(const vector<int>& vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// Utility: print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 2, 6, 3, 4, 5, 6};
    int valToRemove = 6;

    ListNode* head = buildList(vals);
    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* newHead = sol.removeElements(head, valToRemove);

    cout << "After removing " << valToRemove << ": ";
    printList(newHead);

    return 0;
}
