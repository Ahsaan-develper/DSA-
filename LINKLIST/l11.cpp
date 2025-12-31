#include<iostream>
using namespace std;
class Node {
    private:
        int data ;
        Node* next ;
    public:
        Node(int d){
            data = d;
            next = NULL;
        }
        int GetData (){
            return data ;
        }
        Node* GetNext (){
            return next;
        }
        void SetData(int v){
            data = v;
        }
        void SetNext (Node* n){
            next = n;
        }
};
class List {
    private:
        Node* head;
        Node* tail;
    public:
        List(){
            tail=head=NULL;
        }
        void InsertVal(int v){
            Node* newNode = new Node(v);
            if (head==NULL){
                head=tail=newNode;
            }else{
                Node* temp = head;
                tail->SetNext(newNode);
                tail=newNode;
            }
          

        }
         Node* GetHead(){
            return head;
           }
           void SetHead (Node* h){
            head=h;
           }
        void Print (){
            Node* temp = head;
            while (temp != NULL)
            {
                cout <<temp->GetData()<<" ";
                temp = temp->GetNext();
            }
            cout <<endl;
        }
       static Node* MergeRecursive(Node* head1, Node* head2) {
        // base cases
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;

        // recursive comparison
        if (head1->GetData() < head2->GetData()) {
            head1->SetNext(MergeRecursive(head1->GetNext(), head2));
            return head1;
        } else {
            head2->SetNext(MergeRecursive(head1, head2->GetNext()));
            return head2;
        }
    }
};
int main(){
    List l1,l2;
    l1.InsertVal(1);
    l1.InsertVal(2);
    l1.InsertVal(3);
    l1.InsertVal(6);
    l1.Print();
    l2.InsertVal(3);
    l2.InsertVal(4);
    l2.InsertVal(5);
    l2.InsertVal(6);
    l2.Print();
    Node* mergeHead = List::MergeRecursive(l1.GetHead(),l2.GetHead());
    List mergeList;
    mergeList.SetHead(mergeHead);
    mergeList.Print();
    return 0;
}