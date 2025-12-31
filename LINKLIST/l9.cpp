#include<iostream>
using namespace std;
class Node {
    private:
        int data ;
        Node* next ;
    public:
        Node(int d){
            data = d;
            next = NULL;
        }
        int getData (){
            return data ;
        }
        Node* getNext (){
            return next ;
        }
        void setData (int val){
            data = val;
        }
        void setNext (Node* n){
            next = n;
        }
};
class List {
    private:
        Node* head ;
        Node* tail;
    public:
        List(){
            tail=head=NULL;
        }
        void insertHead (int val){
            Node* newNode = new Node(val);
            if (head==NULL){
                head=tail=newNode;
            }else{
                newNode->setNext(head);
                head = newNode;
            }
        }
        void FindMiddle (){
            Node* temp= head;
            int len =0,avg;
            while (temp != NULL)
            {
                len++;
                temp = temp->getNext();
            }
            cout <<" len is : "<<len<<endl;
            avg = len /2;
            cout <<"avg "<<avg <<endl;
            temp= head;
            for (int i=0; i<avg; i++){
                temp = temp ->getNext();
            }
            cout  <<"Middle part is "<<temp->getData() <<endl;
            
        }
        void Print (){
            Node* temp = head;
            while (temp != NULL)
            {
                cout <<temp->getData()<<" ";
                temp = temp ->getNext();
            }      
        }
};
int main(){
    List li;
    li.insertHead(1);
    li.insertHead(2);
    li.insertHead(3);
    li.insertHead(4);
    li.insertHead(5);
    li.insertHead(6);
    li.FindMiddle();
    li.Print();
    return 0;
}