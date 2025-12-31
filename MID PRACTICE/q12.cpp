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
        void makeCircular (){
            if (head==NULL){
            return;
        }
        Node* temp = head;
        
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next= head;
        
        }
        
        void display (){
            Node* temp = head;
           do
           {
            cout <<temp->data<<" ";
                temp =temp ->next;
           } while (temp != head);
           
            cout <<endl;
        }
};
int main(){
    List l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.makeCircular();
    l.display();
    return 0;
}