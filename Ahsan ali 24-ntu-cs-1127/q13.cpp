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
        void Push_End (int val  ){
            Node* newNode = new Node(val);
            if  (head== NULL){
                head=tail=newNode;
            }else{
                tail->SetNext(newNode);
                tail=newNode;
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
    li.Push_End(1);
    li.Push_End(2);
    li.Push_End(3);
    li.Print();
    return 0;
}