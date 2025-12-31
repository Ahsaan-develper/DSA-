#include <iostream>
using namespace std;

// ------------------ NODE CLASS ------------------
class Node {
private:
    int Data;
    Node* Next;
    Node* Previous;

public:
    Node(int data = 0) {
        Data = data;
        Next = Previous = NULL;
    }

    int GetData() { return Data; }
    void SetData(int data) { Data = data; }

    Node* GetNext() { return Next; }
    void SetNext(Node* nextNode) { Next = nextNode; }

    Node* GetPrevious() { return Previous; }
    void SetPrevious(Node* prevNode) { Previous = prevNode; }
};

// ------------------ DOUBLY LIST CLASS ------------------
class DoublyList {
private:
    Node* CurrentLocation;  // points to head of the list

public:
    // Constructor
    DoublyList() {
        CurrentLocation = NULL;
    }

    // Insert a new node at the end
    void InsertNode(int val) {
        Node* newNode = new Node(val);
        if (CurrentLocation == NULL) {
            // if list empty
            CurrentLocation = newNode;
        } else {
            Node* temp = CurrentLocation;
            // move to last node
            while (temp->GetNext() != NULL) {
                temp = temp->GetNext();
            }
            temp->SetNext(newNode);
            newNode->SetPrevious(temp);
        }
        cout << val << " inserted.\n";
    }

    // Delete a node by value
    void DeleteNode(int val) {
        if (CurrentLocation == NULL) {
            cout << "List is empty, cannot delete.\n";
            return;
        }

        Node* temp = CurrentLocation;

        // if head needs to be deleted
        if (temp->GetData() == val) {
            CurrentLocation = temp->GetNext();
            if (CurrentLocation != NULL)
                CurrentLocation->SetPrevious(NULL);
            delete temp;
            cout << val << " deleted.\n";
            return;
        }

        // search node to delete
        while (temp != NULL && temp->GetData() != val) {
            temp = temp->GetNext();
        }

        if (temp == NULL) {
            cout << "Value not found.\n";
            return;
        }

        // if node found in middle or end
        if (temp->GetNext() != NULL)
            temp->GetNext()->SetPrevious(temp->GetPrevious());
        if (temp->GetPrevious() != NULL)
            temp->GetPrevious()->SetNext(temp->GetNext());

        delete temp;
        cout << val << " deleted.\n";
    }

    // Print all nodes
    void PrintList() {
        if (CurrentLocation == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = CurrentLocation;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->GetData() << " ";
            temp = temp->GetNext();
        }
        cout << endl;
    }
};

// ------------------ MAIN FUNCTION ------------------
int main() {
    DoublyList dl;
    dl.InsertNode(10);
    dl.InsertNode(20);
    dl.InsertNode(30);
    dl.PrintList();

    dl.DeleteNode(20);
    dl.PrintList();

    dl.DeleteNode(10);
    dl.PrintList();

    dl.DeleteNode(30);
    dl.PrintList();

    return 0;
}
