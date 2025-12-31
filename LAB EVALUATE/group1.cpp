#include<iostream>
using namespace std;
class Node {
    private:
        int employeId;
        string name ;
        float salary ;
        Node* next ;
    public :
        Node(int i , string n,float s ){
            employeId= i;
            name = n;
            salary = s;
            next=NULL;
        }
        int GetEmployeeId (){
            return employeId;
        }
        string GetName (){
            return name;
        }
        float GetSalary (){
            return salary;
        }
        Node* GetNext (){
            return next;
        }
        void SetEmployeeId(int id){
            employeId = id;
        }
         void SetName(string n){
            name =  n;
        }
         void SetSalary(float s){
            salary = s;
        }
         void SetNext(Node* n){
           next = n;
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
        void InsertAtEnd (int id , string name  , float sal){
            Node* newNode = new Node(id , name , sal);
            if (head==NULL){
                head = tail = newNode;
            }else{
                tail->SetNext(newNode);
                tail= newNode;
            }
        }
        void SearchbyId (){
  int id ;
    cout <<"Enter id to search employee detail"<<endl;
    cin>>id ;
            Node* temp = head;
            while (temp != NULL)
            {
                if (temp->GetEmployeeId() == id ){
                cout << "Id : "<<temp ->GetEmployeeId()<<" "<<endl;
                cout << "Name : "<<temp ->GetName()<<" "<<endl;
                cout << "Salary : "<<temp ->GetSalary()<<" "<<endl;
                return;
                }
                temp= temp ->GetNext();
            }
            
        }
       void Reverse(){
        Node* pre =NULL;
        Node* temp = head;
       while (temp != NULL)
       {
         head = temp->GetNext();
        temp ->SetNext(pre);
        pre = temp ;
        temp = head;
       }
       head = pre;
       }
        void Print (){
            Node* temp = head;

            while (temp != NULL)
            {
                cout << "Id : "<<temp ->GetEmployeeId()<<" "<<endl;
                cout << "Name : "<<temp ->GetName()<<" "<<endl;
                cout << "Salary : "<<temp ->GetSalary()<<" "<<endl;
                temp = temp ->GetNext();
            }
        }

};
int main(){
    List li ;
  
    li.InsertAtEnd(1,"ali", 1000);
    li.InsertAtEnd(2,"ahsan", 100000);
    li.InsertAtEnd(3,"ghulam", 10000);
    li.InsertAtEnd(4,"habib", 16788);
   li.Reverse();
    cout <<" Over all All Employees details "<<endl;
    li.Print();
     li.SearchbyId();
}