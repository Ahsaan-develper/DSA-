#include<iostream>
using namespace std;
class Node {
    public:
        int data ;
        Node* next;
        Node(int d){
            data= d;
            next= NULL;
        }
};
class List{
    private :
        Node* head;
        Node* tail;
    public:
        List(){
            tail=head=NULL;
        }
        void add_Back (int val){
            Node* newNode = new Node(val);
            if (head==NULL){
                head=tail=newNode;
            }else{
                tail->next= newNode;
                tail= newNode;
            }
        }
        void print(){
            Node* temp =head;
            while (temp != NULL)
            {
                cout <<temp->data<<" ";
                temp =temp->next;
            }
            
        }
};
int main(){
    List li;
    li.add_Back(1);
    li.add_Back(2);
    li.add_Back(3);
    li.print();
    return 0;
}