#include<iostream>
using namespace std;
class Node {
    public:
        int data ;
        Node* next ;
        Node(int  d){
            data=d;
            next= NULL;
        }
};
class List {
    Node* head ;
    Node* tail;
    public:
        List(){
            head=tail=NULL;
        }
        void add_front (int val){
            Node* newNode = new Node(val);
            if (head == NULL){
                head=tail=newNode;
            }else{
                newNode->next=head;
                head=newNode;
            }
        }
        void Value (int val ){
            Node* temp = head;
            int count=0;
            while (temp != NULL)
            {
                count++;
                if (temp->data== val){
                   
                    cout <<"value found at index : "<<count<<endl;
                    
                    return;
                }else{
                    temp=temp->next;
                }
                
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
    li.add_front(1);
    li.add_front(2);
    li.add_front(3);
    li.Value(2);
    li.print();
    return 0;
}