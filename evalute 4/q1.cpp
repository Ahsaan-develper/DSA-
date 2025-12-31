#include<iostream>
using namespace std;
class Node {
    private:
        int tokenNumber ;
        string C_Name ;
        string s_type ;
        Node* next;
    public :
        int GetTokenNO(){
            return tokenNumber;
        }
         string GetName(){
            return C_Name;
        }
         string GetType(){
            return s_type;
        }
        Node* GetNext (){
            return next;
        }
        void SetTokenNumber (int t){
            tokenNumber= t;
        }
        void SetName (string n){
            C_Name= n;
        }
        void SetType (string s){
            s_type= s;
        }
        void SetNext (Node* nx){
            next = nx;
        }

};
class Queue{
    private :
        Node* front ;
        Node* rear;
    public:
        Queue (){
            front = rear= NULL;
        }
        void enqueue(int num , string name , string type ){
            Node* newNode = new Node;
            newNode->SetName(name);
            newNode->SetNext(NULL);
            newNode->SetTokenNumber(num);
            newNode->SetType(type);
            if (front== NULL){
                front = rear= newNode;
            }else{
                rear->SetNext(newNode);
                rear= newNode;
            }
        }
        void dequeue (){
            if (front == NULL){
                cout <<"Queue is empty "<<endl;
                return;
            }else{
                Node* temp = front;
                front = front->GetNext();
                delete temp;
            }
        }
        void display(){
            if (front == NULL){
                cout <<"Queue is empty "<<endl;
                return;
            }else{
                Node* temp = front;
                while (temp != NULL)
                {
                    cout <<temp->GetTokenNO() <<" "<<temp->GetName()<<" "<<temp->GetType()<<" ";
                    temp = temp ->GetNext();
                }
                cout <<endl;
            }
        }
};
int main(){
    Queue q;
    q.enqueue(101, "ali","Depost");
    q.enqueue(102, "sara","account open");
    q.enqueue(103, "bilal","fund tranfer");
    q.display();
    cout <<"After First work done "<<endl;
    q.dequeue();
    q.display();
    return 0;
}