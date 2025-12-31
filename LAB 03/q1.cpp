#include<iostream>
using namespace std;
class Node{
    private:
        int data ;
        Node* next;
    public:
        int GetData(){
            return data;
        }
        Node* GetNext(){
            return next;
        }
        void SetData (int val){
            data = val;
        }
        void SetNext (Node* ptr){
            next=ptr;
        }

};

int main(){
    Node n1,n2;
    n1.SetData(10);
    n2.SetData(20);
    n1.SetNext(&n2);
    cout <<"Data in n1 : "<<n1.GetData()<<endl;
    cout <<"Data in n2 : "<<n2.GetData()<<endl;
    cout <<"Data in n2 through n1 : "<<n1.GetNext()->GetData()<<endl;

    return 0;
}