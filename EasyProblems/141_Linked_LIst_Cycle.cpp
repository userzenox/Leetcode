#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Solution Class */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle
    }
};

/* Main Function */
int main() {
    // Create nodes
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create a cycle (connecting last node to 2nd node)
    head->next->next->next->next = head->next; // cycle at node with value 2

    Solution solution;
    bool result = solution.hasCycle(head);

    if (result) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
