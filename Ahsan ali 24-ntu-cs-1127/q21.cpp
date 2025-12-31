#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }

    void SetNext(Node* n) {   // ✅ correct setter
        next = n;
    }

    Node* GetNext() {         // ✅ correct getter
        return next;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = tail = NULL;
    }

    // Insert node at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->SetNext(newNode);
            tail = newNode;
        }
    }

    // Convert to circular linked list
    void convertToCircular() {
        if (head == NULL) return;
        tail->SetNext(head);  // ✅ link last node to first node
    }

    // Display circular linked list (using while loop)
    void displayCircular() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (true) {       // 🔁 infinite loop until we break manually
            cout << temp->data << " ";
            temp = temp->GetNext();
            if (temp == head) break;  // break when back to start
        }
        cout << endl;
    }
};

// Main function
int main() {
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Converting to circular linked list..." << endl;
    list.convertToCircular();

    cout << "Circular Linked List contents: ";
    list.displayCircular();

    return 0;
}
