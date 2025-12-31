#include<iostream>
using namespace std;
class Node {
    private:
        int data ;
        Node* next ;
    public:
        int getData (){
            return data;
        }
        Node* getNext (){
            return next;
        }
        void setData (int d){
            data =d;
        }
        void setNext (Node* n){
            next = n;
        }
};
class Queue {
    private:
        Node* front ;
        Node* rear;
    public:
        Queue(){
            front = rear = NULL;
        }
        void enqueue(int val){
            Node* newNode = new Node;
            newNode->setData(val);
            newNode->setNext(NULL);
            if (front== NULL){
                front= rear= newNode;
            }else{
                rear->setNext(newNode);
                rear= newNode;
                cout <<"new node is"<<val<<endl;
            }
        }
        void dequeue(){
            if (front== NULL){
                cout <<"queue is empty "<<endl;
                return;
            }else{
                 Node* temp =front;
                 front= front->getNext();
                 temp->setNext(NULL);
                 delete temp;
            }
        }
        void Display (){
            Node* temp = front;
            while (temp != NULL)
            {
                cout <<temp->getData() <<" ";
                temp = temp->getNext();
            }
            cout<<endl;
        } 
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.Display();
    q.dequeue();
    q.Display();
    return 0;
}