#include <iostream>
using namespace std;

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to find the first middle element of the linked list in case of an even-sized list
Node* findFirstMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;  // If list is empty or has 1 node

    Node* slow = head;        // Start slow at the head
    Node* fast = head->next;  // Start fast one step ahead

    // Traverse the list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // Move slow one step
        fast = fast->next->next;   // Move fast two steps
    }

    // When the loop ends, slow is at the first middle element
    return slow;
}

// Helper function to add nodes to the linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;  // Used to traverse the list
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

int main() {
    Node* head = nullptr;

    // Add elements to the list (even size)
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    append(&head, 60);

    Node* firstMiddle = findFirstMiddle(head);

    if (firstMiddle != nullptr) {
        cout << "The first middle element is: " << firstMiddle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
