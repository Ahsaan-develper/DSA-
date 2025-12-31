#include<iostream>
using namespace std;
class Node {
    private:
        int data ;
        Node* next;
    public:
        Node (int  d){
            data = d;
            next = NULL;
        }
        int GetData(){
            return data ;
        }
        Node* GetNext (){
            return next;
        }
        void SetData (int v){
            data =v;
        }
        void SetNext (Node* n){
            next = n;
        }
};
class List {
    private:
        Node* head ;
        Node* tail;
    public:
        List(){
            head=tail=NULL;
        }
        void InsertTail(int val){
            Node* newNode = new Node(val);
            if (head==NULL){
                tail=head=newNode;
            }else{
                tail->SetNext(newNode);
                tail=newNode;
            }
        }
        void Print (){
            Node* temp = head;
            while (temp != NULL)
            {
             cout <<   temp ->GetData()<<" ";
                temp = temp->GetNext();
            }
            
        }
        void DetectCycle (){
            Node* slow = head;
            Node* fast= head;
            bool foundCycle = false;
            while (fast != NULL &&  fast->GetNext() != NULL)
            {
                slow= slow->GetNext();
                fast= fast->GetNext()->GetNext();
                if (slow == fast){
                    foundCycle = true;
                }
                foundCycle= false;
            }
            if (foundCycle){
                cout <<"Cycle detect"<<endl;
            }else{
                cout <<"Cycle not detect"<<endl;
            }
            
        }
};
int main(){
    List li;
    li.InsertTail(1);
    li.InsertTail(2);
    li.InsertTail(3);
    li.InsertTail(4);
    li.DetectCycle();
    li.Print();
    return 0;
}