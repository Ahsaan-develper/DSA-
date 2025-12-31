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
            cout <<val<<" Value add at end"<<endl;
        }
        void dequeue(){
            if (front== NULL){
                cout <<"Queue is underflow "<<endl;
                return;
            }else{
                Node* temp = front;
                front= front->GetNext();
                cout <<temp->GetData()<<" Value delete "<<endl;
                delete temp;
                        }
        }
        void printQueue(){
            if (front==NULL){
                cout <<"Queue is empty"<<endl;
                return;
            }else{
                Node*  temp = front;
                cout <<"Values are : ";
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
    int choice ,val;
    do {
        cout <<"Enter 1 do add value into queue at rear"<<endl;
        cout <<"Enter 2 do delete value  from front of queue"<<endl;
        cout <<"Enter 3 do display all values from queue"<<endl;
        cout <<"Enter 4 to exit system"<<endl;
        cin>>choice;

        switch (choice)
    {
    case 1:
        cout <<"Please enter value here !"<<endl;
        cin>>val;
        q.enqueue(val);
        break;
    case 2:
        q.dequeue();
        break;
    case 3:
        q.printQueue();
        break;
    case 4:
        cout <<"System is exit here !"<<endl;
        break;
    
    default:
        cout <<"Choice in invalid"<<endl;
        break;
    }
    }while (choice != 4);
   
    
    return 0;
}
