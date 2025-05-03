#include <iostream>
#include <vector>
#include <unordered_map>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> seen;
        for (int num : nums) {
            seen[num] = true;
        }

        // Handle nodes at the start that need to be removed
        while (head && seen[head->val]) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* curr = head;
        while (curr && curr->next) {
            if (seen[curr->next->val]) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// Main function to test
int main() {
    Solution sol;

    vector<int> listValues = {1, 2, 6, 3, 4, 5, 6};
    vector<int> toRemove = {6, 3};

    ListNode* head = createList(listValues);
    cout << "Original list: ";
    printList(head);

    ListNode* modified = sol.modifiedList(toRemove, head);
    cout << "Modified list: ";
    printList(modified);

    // Cleanup remaining nodes
    while (modified) {
        ListNode* temp = modified;
        modified = modified->next;
        delete temp;
    }

    return 0;
}
