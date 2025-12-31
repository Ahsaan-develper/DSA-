#include<iostream>
using namespace std ;
class Node {
    public:
        int data ;
        Node* next ;
    
        Node(int d){
            data = d;
            next= NULL;
        }
};
class Stack {
    private:
        Node* top ;
    public:
        Stack(){
            top= NULL;
        }
        void Push (int val){
            Node* newNode = new Node(val);
            newNode->next = top;
            top = newNode;
            cout <<" value  push : "<<val<<endl;
        }
        void Pop(){
            if (top==NULL){
                cout <<"Stack underflow"<<endl;
            }else{
                cout <<top->data<<" popped from stack"<<endl;
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }

        void Peek (){
            if (top==NULL){
                cout <<"Stack is empty "<<endl;
            }else{
                cout << "Top element is: " << top->data << endl;
            }
        }
        void Display (){
        if (top == NULL) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main(){
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Peek();
    s.Display();
    cout <<" After pop"<<endl;
    s.Pop();
    s.Display();

    return 0;
}