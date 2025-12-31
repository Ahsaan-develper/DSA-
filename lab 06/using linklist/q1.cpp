#include<iostream>
using namespace std;
class Node {
    private :
        int data ;
        Node* next ;
    public:
        int GetData (){
            return data ;
        }
        Node* GetNext (){
            return next;
        }
        void setData (int  d){
            data = d;
        }
        void setNext (Node* n){
            next=n;
        }
};
class LinkListQueue{
    private:
        Node* front ;
        Node* rear;
    public:
        LinkListQueue(){
            front= rear = NULL;
        }
        void enqueue(int val){
            Node* newNode = new Node;
              newNode->setNext(NULL);
              newNode->setData(val);
            if (front== NULL){
                front= rear= newNode;
            }else{
                rear->setNext(newNode);
                rear= newNode;
            }
        }
        void dequeue(){
            if (front== NULL){
                cout <<"Queue is underflow "<<endl;
                return;
            }else{
                Node* temp = front;
                front= front->GetNext();
                delete temp;
            }
        }
        void printQueue(){
            if (front==NULL){
                cout <<"Queue is empty"<<endl;
                return;
            }else{
                Node*  temp = front;
                while (temp != NULL)
                {
                    cout<<temp->GetData() << " ";
                    temp =temp->GetNext();
                }
                cout <<endl;
            }
        }
        bool isEmpty (){
            return front==NULL;
        }
        int getFront (){
            if (front==NULL){
                cout <<"Queue is empty "<<endl;
                return -1;
            }else{
                return front->GetData();
            }
        }
};
int main(){
    LinkListQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.printQueue();
    q.dequeue();
    q.printQueue();
    cout <<q.getFront();
    return 0;
}
