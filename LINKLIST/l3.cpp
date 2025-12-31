#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next ;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class List {
    Node* head;
    Node* tail;
    public:
        List(){
            head=tail=NULL;
        }
        void push_head(int val){
        Node* newNode= new Node(val);
            if (head==NULL){
                head=tail=newNode;
                return;
            }else{
                newNode->next=head;
                head=newNode;
            }
        }
        void push_back (int val){
              Node* newNode= new Node(val);
            if (tail==NULL){
                tail=head=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        void pop_head (){
            Node* temp = head;
            if (temp==NULL){
                cout <<"Node is empty "<<endl;
                return ;
            }else{
                head=head->next;
                temp->next=NULL;
                delete temp;
            }
        }
        void pop_back(){
            Node* temp = head;
            if (temp==NULL){
                cout <<"Node is empty "<<endl;
                return;
            }else{
                while (temp->next !=tail){
                    temp= temp->next;
                }
               temp->next=NULL;
               delete tail;
               tail=temp;
                
            }
        }
        void print (){
            Node* temp = head;
           while (temp != NULL)
           {
            cout <<temp->data<<" ";
            temp= temp->next;
           }
           
            
        }
};
int main(){
    List li;
    li.push_back(1);
    li.push_head(2);
    li.push_head(3);
    li.push_head(4);
    li.pop_head();
    li.pop_back();
    li.print();
    return 0;
}