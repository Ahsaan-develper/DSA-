// LinkedList_MinHeap.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class MinHeapLL {
    Node* head;
    int size;

    Node* getNode(int index) {
        Node* temp = head;
        for (int i = 1; i < index; i++)
            temp = temp->next;
        return temp;
    }

public:
    MinHeapLL() {
        head = NULL;
        size = 0;
    }

    void insert(int val) {
        Node* newNode = new Node{val, NULL};
        size++;

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;

        int i = size;
        while (i > 1) {
            int parent = i / 2;
            Node* curr = getNode(i);
            Node* par = getNode(parent);

            if (par->data > curr->data) {
                swap(par->data, curr->data);
                i = parent;
            } else {
                break;
            }
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    MinHeapLL h;
    h.insert(40);
    h.insert(20);
    h.insert(50);
    h.insert(10);

    cout << "Min Heap (Linked List):\n";
    h.print();
    return 0;
}
