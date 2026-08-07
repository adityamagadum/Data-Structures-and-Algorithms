#include <bits/stdc++.h> 
using namespace std;

// Class definition for a Doubly Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* prvs; // Pointer to the previous node

    // Constructor to easily initialize a new node
    Node(int val) {
        data = val;
        next = nullptr;
        prvs = nullptr;
    }
};

// Function to insert a node at the front of the list
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head != nullptr) {
        head->prvs = newNode;
        newNode->next = head;
    }
    head = newNode;
}

// Function to insert a node at the end of the list
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prvs = temp;
}

// Function to delete a node by its value
void deleteNode(Node*& head, int val) {
    if (head == nullptr) return;

    Node* temp = head;

    // Search for the node to delete
    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
    }

    // Value not found in the list
    if (temp == nullptr) return;

    // If the node to be deleted is the head node
    if (head == temp) {
        head = temp->next;
    }

    // Change next only if the node to be deleted is NOT the last node
    if (temp->next != nullptr) {
        temp->next->prvs = temp->prvs;
    }

    // Change prvs only if the node to be deleted is NOT the first node
    if (temp->prvs != nullptr) {
        temp->prvs->next = temp->next;
    }

    delete temp; // Free memory
}

// Function to print the list from head to tail
void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward List: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to print the list from tail to head
void displayBackward(Node* head) {
    if (head == nullptr) return;
    
    Node* temp = head;
    // Move to the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    cout << "Backward List: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prvs;
    }
    cout << "NULL" << endl;
}

// Main execution function
int main() {
    Node* head = nullptr;

    // Perform list insertions
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5);

    // Display the list layouts
    displayForward(head);
    displayBackward(head);

    // Perform list deletion
    cout << "\nDeleting node 20..." << endl;
    deleteNode(head, 20);

    // Re-verify the lists
    displayForward(head);
    displayBackward(head);

    return 0;
}
