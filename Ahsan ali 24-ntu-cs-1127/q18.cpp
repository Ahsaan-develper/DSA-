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

    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->SetNext(head);
        head = newNode;
    }

    void Reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->GetNext();   // Save next
            curr->SetNext(prev);      // Reverse link
            prev = curr;              // Move prev forward
            curr = next;              // Move curr forward
        }

        head = prev; // New head
    }

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
    li.push_front(4);

    cout << "Original List: ";
    li.Print();

    li.Reverse();

    cout << "Reversed List: ";
    li.Print();

    return 0;
}
