#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int d) {
        data = d;
        next = NULL;
    }

    int GetData() { return data; }
    Node* GetNext() { return next; }
    void SetNext(Node* n) { next = n; }
};

class List {
private:
    Node* head;

public:
    List() {
        head = NULL;
    }

    // Insert node at start
    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->SetNext(head);
        head = newNode;
    }

    // Delete node by position
    void DeleteAtAnyKey(int pos) {
        // If list empty
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // If position is invalid
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* temp = head;

        // If deleting first node
        if (pos == 0) {
            head = head->GetNext();
            delete temp;
            return;
        }

        // Move to node before the one to delete
        Node* prev = NULL;
        for (int i = 0; temp != NULL && i < pos; i++) {
            prev = temp;
            temp = temp->GetNext();
        }

        // If position is out of range
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }

        // Skip and delete
        prev->SetNext(temp->GetNext());
        delete temp;
    }

    // Print list
    void Print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->GetData() << " ";
            temp = temp->GetNext();
        }
        cout << endl;
    }
};

int main() {
    List li;
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);

    cout << "Before deletion: ";
    li.Print();

    li.DeleteAtAnyKey(1); // delete node at position 1

    cout << "After deletion: ";
    li.Print();

    return 0;
}
