#include<iostream>
using namespace std;
class Node {
    private:
        int data ;
        Node* next ;
    public:
        Node (int d){
            data =  d;
            next= NULL;
        }
        int GetData (){
            return data ;
        }
        Node* GetNext (){
            return next;
        }
        void SetData (int v){
            data = v;
        }
        void SetNext (Node* n){
            next=n;
        }
};
class List {
    private:
        Node* head;
        Node* tail;
    public:
        List(){
            head= tail=NULL;
        }
       void AtGivenPoint(int val , int pos){
        Node* newNode = new Node(val);
        if (head==NULL){
            head=tail=newNode;
            return;
        }
        if (pos<0){
            cout <<"You enter wrong position "<<endl;
            return;
        }

        if (pos==0){
            newNode->SetNext(head);
            head= newNode;
            return;
        }else{
            Node* temp = head;
            while (temp != NULL && pos -1 )
            {
                temp = temp->GetNext();
            }
           
            if (temp ==NULL){
                cout <<"Pos Out of range "<<endl;
                delete newNode;
                return;
            }else{
                 newNode->SetNext(temp->GetNext());
            temp->SetNext(newNode);
            }
            if (newNode->GetNext()==NULL){
                tail=newNode;
            }
        }

       }
        void Print  (){
            Node* temp = head;
            while (temp != NULL)
            {
                cout <<temp ->GetData() <<" ";
                temp = temp ->GetNext();
            }  
        }
};
int main(){
    List li;
   li.AtGivenPoint(0,0);
   li.AtGivenPoint(1,0);
   li.AtGivenPoint(2,0);
   li.AtGivenPoint(5,1);
    li.AtGivenPoint(3,3);
    li.Print();
    return 0;
}