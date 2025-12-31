#include <iostream>
using namespace std;
class Node {
    public:
        int data ;
        Node* next ;
        Node(int d){
            data= d;
            next=NULL;
        }
};
class List {
    private :
        Node* head;
        Node* tail;
    public:
    List(){
        tail=head=NULL;
    }
        void add_front (int val){
            Node* newNode = new Node(val);
            if (head== NULL){
                head=tail= newNode;
            }else{
                newNode->next= head;
                head= newNode;
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
        void Reverse (){
            Node* curr = head;
            Node* pre=NULL;
            Node* next= NULL;
            while (curr != NULL)
            {
                next= curr->next;
                curr->next=pre;
                pre=curr;
                curr=next;
            }
            head= pre;
        }
};
int main(){
    List li;
    li.add_front(1);
    li.add_front(2);
    li.add_front(3);
    cout <<"Original :"<<endl;
    li.print();
    li.Reverse();
    cout <<"Reverse :"<<endl;
    li.print();

    return 0;
}