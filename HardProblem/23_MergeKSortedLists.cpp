#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    // Custom comparator for min-heap
    class cmp {
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;  // min heap based on node value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> mh;

        // Push all non-null list heads into heap
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL){
                mh.push(lists[i]);
            }
        }
      
        ListNode* head = NULL;
        ListNode* tail = NULL;

        // Extract min and push next node from same list
        while(!mh.empty()){
            ListNode* top = mh.top();
            mh.pop();

            if(top->next != NULL){
                mh.push(top->next);
            }

            if(head == NULL){
                head = top;
                tail = top;
            } 
            else {
                tail->next = top;
                tail = tail->next;
            }
        }
        return head;
    }
};

// Helper function to print a linked list
void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    
    // Example input: 3 sorted linked lists
    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(5);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    ListNode* c = new ListNode(2);
    c->next = new ListNode(6);

    vector<ListNode*> lists = {a, b, c};

    Solution s;
    ListNode* mergedHead = s.mergeKLists(lists);

    cout << "Merged Sorted Linked List: ";
    printList(mergedHead);

    return 0;
}
