#include <iostream>
using namespace std;

// Node structure for linked list
class Node {
public:
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* Top; // pointer to top of stack

public:
    // Constructor: initialize Top to NULL (empty stack)
    Stack() {
        Top = NULL;
    }

    // Check if stack is empty
    bool IsEmpty() {
        return (Top == NULL);
    }

    // Check if stack is full (for linked list, usually never full unless memory runs out)
    bool IsFull() {
        // Try to allocate memory for new node
        Node* temp = new(nothrow) Node;
        if (temp == NULL)
            return true;
        delete temp;
        return false;
    }

    // Return size of stack
    int Size() {
        int count = 0;
        Node* temp = Top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Push element into stack
    void Push(int val) {
        if (IsFull()) {
            cout << "Stack Overflow! Cannot push " << val << endl;
        } else {
            Node* newNode = new Node;
            newNode->data = val;
            newNode->next = Top;
            Top = newNode;
            cout << val << " pushed into stack." << endl;
        }
    }

    // Pop element from stack
    void Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            Node* temp = Top;
            cout << "Popped value: " << Top->data << endl;
            Top = Top->next;
            delete temp;
        }
    }

    // Display all elements in stack
    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            Node* temp = Top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Stack stk;

    stk.Push(100);
    stk.Push(200);
    stk.Push(300);
    stk.Push(400);
    stk.Push(500);
    stk.Display();

    cout << "\nPopping...\n";
    stk.Pop();

    stk.Display();

    system("pause");
    return 0;
}
