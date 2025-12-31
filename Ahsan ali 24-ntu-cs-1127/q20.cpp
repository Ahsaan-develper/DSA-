#include<iostream>
using namespace std;
class Node {
    private:
        int data ;
        Node* next ;
        Node* pre ;
    public:
        Node (int d){
            data =  d;
            next=pre= NULL;
        }
        int GetData (){
            return data ;
        }
        Node* GetNext (){
            return next;
        }
        Node* GetPre (){
            return pre;
        }
        void SetData (int v){
            data = v;
        }
        void SetNext (Node* n){
            next=n;
        }
        void SetPre (Node* p){
            pre= p;
        }
};
class DoublyList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyList(){
            head= tail=NULL;
        }
        void push_front (int val  ){
            Node* newNode = new Node(val);
            if  (head== NULL){
                head=tail=newNode;
            }else{
                newNode->SetNext(head);
                head->SetPre(newNode);
                newNode->SetPre(NULL);
                head= newNode;
            }
        }
        void Push_End (int val){
            Node* newNode = new Node(val);
            if (head==NULL){
                tail=head=NULL;
            }else{
                tail->SetNext(newNode);
                newNode->SetPre(tail);
                newNode->SetNext(NULL);
                tail=newNode;
            }
        }
       void InsertAtAnyPos(int val, int pos) {
    Node* newNode = new Node(val);

    if (pos < 0) {
        cout << "Enter valid position" << endl;
        delete newNode;
        return;
    }

    if (pos == 0) {
        newNode->SetNext(head);
        if (head != NULL)
            head->SetPre(newNode);
        head = newNode;
        if (tail == NULL)
            tail = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->GetNext();
    }
    if (temp == NULL) {
        cout << "Position out of range" << endl;
        delete newNode;
        return;
    }

    newNode->SetNext(temp->GetNext());
    newNode->SetPre(temp);

    if (temp->GetNext() != NULL)
        temp->GetNext()->SetPre(newNode);
    else
        tail = newNode; // inserted at end

    temp->SetNext(newNode);
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
    DoublyList li;
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.Push_End(2);
    li.Push_End(3);
    li.InsertAtAnyPos(2,5);
    li.Print();
    return 0;
}