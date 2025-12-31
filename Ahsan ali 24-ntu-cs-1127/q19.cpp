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
        void push_front (int val  ){
            Node* newNode = new Node(val);
            if  (head== NULL){
                head=tail=newNode;
            }else{
                newNode->SetNext(head);
                head= newNode;
            }
        }
        void MiddleLinkList (){
            Node* temp = head;
            int count =0;
            while (temp != NULL)
            {
                count++;
                temp = temp->GetNext();
            }
            cout <<" No of nodes are : "<<count<<endl;
            int middle = count / 2;
            temp = head;
            int ans =0;
            for(int i=0 ; i<middle ; i++){
                temp = temp ->GetNext();
            }
            cout <<"Middle of link list is "<< temp->GetData()<<endl;
            
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
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_front(4);
    li.push_front(5);
    li.MiddleLinkList();
    li.Print();
    return 0;
}