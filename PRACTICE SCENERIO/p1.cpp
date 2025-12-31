#include<iostream>
using namespace std;
class Node {
    private:
        int id ;
        string priority ;
        string time;
        Node* next ;
        Node* pre ;
    public:
        Node(int i , string p , string t){
            id = i;
            priority = p;
            time = t;
            next= pre = NULL;
        }
        int GetId(){
            return id;
        }
        string GetPriority(){
            return priority;
        }
        string GetTime(){
            return time;
        }
         Node* GetNext(){
            return next;
        }
         Node* GetPre(){
            return pre;
        }
        void SetId(int i){
            id = i;
        }
        void SetPriority(string p){
            priority = p;
        }
        void SetTime(string t){
           time  = t;
        }
        void SetNext(Node* n){
            next = n;
        }
        void SetPre(Node* p){
           pre = p;
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
        void InsertValue (int id, string prio , string t ){
            Node* newNode = new Node(id, prio, t);
            if(head==NULL){
                head= tail = newNode;
               newNode->SetPre(NULL);
               newNode->SetNext(NULL);
            }else{
                newNode ->SetNext(head);
                newNode->SetPre(NULL);
                head = newNode;
            }
        }
        void Print (){
            
        }
};
int main(){
    List li;
    li.InsertValue(1,"low","30min");
    li.InsertValue(2,"medium","60min");
    li.InsertValue(3,"high","1.4hour");
}