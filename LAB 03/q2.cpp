#include<iostream>
using namespace std ;
class Node {
    private:
        int data ;
        Node* next ;
    public:
        Node(int d){
            data =d ;
            next = NULL;
        }
        int GetData(){
           return data;
        }
        Node* GetNext (){
          return  next;
        }
        void Setdata (int val){
            data = val;
        }
        void SetNext (Node* ptr){
            next = ptr;
        }
};
class List {
    private:
        Node* head;
    public:
        List(){
            head=NULL;
        }
       void insert (int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head=newNode;
        }else{
           Node*  temp = head;
           while (temp->GetNext() != NULL)
           {
            temp= temp->GetNext();
           }
           temp->SetNext(newNode);
          
        }
       }
       void print(){
        Node* temp = head;
        while (temp != NULL)
        {
            cout <<temp->GetData()<<" ";
            temp=temp->GetNext();
        }
        cout <<endl;

       }
       void addBetween (int val){
       
        if (head==NULL || head->GetNext()==NULL){
        cout <<"Not enough node to add new node between "<<endl;
        return;
       }else{
        Node* newNode = new Node(val);
        newNode->SetNext(head->GetNext());
        head->SetNext(newNode);
       }
    }
    void Delete (int val){
        if (head==NULL){
            cout <<"List is empty "<<endl;
            return;
        }else{
            if (head->GetData()==val){
                Node* temp = head;
                head= head->GetNext();
                delete temp;
                return;
            }  
        }
        Node* temp = head;
        while (temp->GetNext() != NULL && temp->GetNext()->GetData()!= val)
        {
            temp= temp->GetNext();
        }
        if (temp->GetNext() == NULL){
            cout <<"Value not foundin list"<<endl;
            return;
        }else{
            Node* del =temp->GetNext();
            temp ->SetNext(del->GetNext());
            delete del;
        }
        
    }
};
int main(){
    List li;
    li.insert(1);
    li.insert(2);
    li.insert(3);
    li.insert(4);
    li.insert(5);
    cout <<"Inserting nums "<<endl;
    li.print();
    cout <<"Add between "<<endl;
    li.addBetween(6);
    li.print();
    cout <<"Delete a number "<<endl;
    li.Delete(5);
    li.print();

    return 0;
}