#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node *next;

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
    }

    // Constructor with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Constructor with data and next pointer
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Recursive function to reverse the linked list
void reverse(Node* &head, Node* curr, Node* prev) {
    // Base case
    if (curr == NULL) {
        head = prev;
        return;
    }

    Node* forward = curr->next;  // Save the next node
    reverse(head, forward, curr);  // Recursively reverse the rest of the list
    curr->next = prev;  // Point the current node to the previous node
}

// Wrapper function for reversing the linked list
Node* reverseLinkedList(Node *head) {
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);  // Initiate recursive reversal
    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed list
    cout << "Reversed List: ";
    printList(head);

    return 0;
}