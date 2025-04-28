#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> st;

        // Push first half elements into stack
        while (fast != NULL && fast->next != NULL) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If odd number of elements, move slow one step ahead
        if (fast != NULL) {
            slow = slow->next;
        }

        // Compare second half with stack
        while (slow != NULL) {
            int top = st.top();
            st.pop();
            if (top != slow->val) {
                return false;
            }
            slow = slow->next;
        }

        return true;
    }
};

// Helper function to create a linked list
ListNode* createList(vector<int> values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    for (int i = 1; i < values.size(); i++) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Input: 1 -> 2 -> 3 -> 2 -> 1
    vector<int> values = {1, 2, 3, 2, 1};
    ListNode* head = createList(values);

    cout << "Linked List: ";
    printList(head);

    Solution sol;
    bool result = sol.isPalindrome(head);

    if (result) {
        cout << "The linked list is a Palindrome." << endl;
    } else {
        cout << "The linked list is NOT a Palindrome." << endl;
    }

    return 0;
}
