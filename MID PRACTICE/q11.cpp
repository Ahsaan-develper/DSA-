#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
};
class List {
    private:
        Node* head;
        Node* tail;
    public:
        List(){
            head= tail= NULL;
        }
        void push (int val){
            Node* newNode =  new Node;
             newNode->next=NULL;
                newNode->data=val;
            if (head==NULL){
               
                head= tail= newNode;
            }else{
                newNode->next= head;
                head= newNode;
            }
        }
        void Deleteatany( int pos){
            Node * temp = head;
            int count =0;
            while (temp != NULL &&count < pos -1)
            {
                temp = temp ->next;
                count ++;
            }
            if (temp ==NULL &&temp ->next==NULL){
                cout <<"Pos out of range"<<endl;
                return;
            }
                Node* nodeDelete = temp->next;
                temp->next= nodeDelete->next;
                delete nodeDelete;
        }   
        void display (){
            Node* temp = head;
            while (temp != NULL)
            {
                cout <<temp->data<<" ";
                temp =temp ->next;
            }
            cout <<endl;

            
        }
};
int main(){
    List l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    
    l.display();
    l.Deleteatany(2);
    l.display();
    return 0;
}