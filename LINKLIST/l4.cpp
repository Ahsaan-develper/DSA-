#include<iostream>
using namespace std;
class Node {
    public:
        int data ;
        Node* next ;
        Node(int d){
            data=d;
            next=NULL;
        }

};
class List {
    Node* head ;
    Node* tail;
    public:
        List(){
            head=tail=NULL;
        }
        void add_head(int val){
            Node* newNode = new Node(val);
            if (head==NULL){
                head=tail=newNode;
            }else{
                newNode->next=head;
                head=newNode;
            }
        }
        void add_back (int val){
            Node* newNode = new Node(val);
            if (tail==NULL){
                cout <<"List is empty "<<endl;
                return;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        void pop_head(){
            Node* temp = head;
           if (temp==NULL){
            cout <<"List is empty "<<endl;
            return;
           }else{
            head= head->next;
            temp->next=NULL;
            delete  temp;
           }
            
        }
        void insert (int val ,int pos){
            Node* temp = head;
            if (pos<0){
                cout <<"List position is wrong"<<endl;
                return ;
            }else if (pos==0){
                add_head(val);
                return;
            }else{
                for (int i=0 ; i<pos-1;i++ ){
                    temp= temp->next;
                }
                Node* newNode = new Node(val);
                newNode->next= temp->next;
                temp->next=newNode;
            }

        }
        void print (){
            Node* temp = head;
            while (temp != NULL)
            {
                cout <<temp->data<<" ";
                temp=temp->next;
            }
        }
};
int main(){
    List li;
    li.add_head(1);
    li.add_head(2);
    li.add_head(3);
    li.add_head(4);
    li.add_back(5);
    // li.pop_head();
    li.insert(6,2);
    li.insert(1,0);
    li.print();
    return 0;
}