#include <iostream>
using namespace std ;
class Node {
    public:
        int data ;
        Node* next ;
        Node(int d){    // constructor
            data = d;
            next = NULL;
        }
        
};
class List {
        Node* head;
        Node* tail;
    public:
        List(){
            tail=head=NULL;
        }
        void Ad_back (int val){
            Node* newNode = new Node(val);
            if (head==NULL){
                head=tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        void insert(int val , int pos){
            Node* newNode= new Node(val);
            Node* temp = head;
            if (pos<0){
                cout <<"You enter wrong position"<<endl;
                return;
            }else{
                 for (int i=0 ; i<pos;i++){
                temp=temp->next;
            }
              newNode->next=temp->next;
               temp->next=newNode;
             
            }
        }
        void find (int pos){
            Node* temp = head;
           for (int i=0; i<pos;i++){
            temp= temp->next;
           }
           cout<<"Find : " <<temp->data<<endl;
            
        }
        void print (){
            Node* temp = head;
            while (temp !=NULL)
            {
               cout <<temp->data<<" ";
               temp= temp->next;
            }      
        }
};
int main(){
    List li;
    li.Ad_back(1);
    li.Ad_back(2);
    li.Ad_back(3);
    li.Ad_back(4);
    li.insert(5,3);
    li.insert(10,2);
    li.find(2);
    li.print();
    return 0;
}