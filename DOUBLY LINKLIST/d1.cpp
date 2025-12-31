#include <iostream>
using namespace std;
class Node {
    private:
        int data ;
        Node* next;
        Node* pre ;
    public:
        Node(int d){
            data = d;
            next= pre= NULL;
        }
        Node* GetNext (){
            return next;
        }
        int GetData (){
            return data;
        }
        Node* GetPre(){
            return pre;
        }
        void SetData (int d){
            data =d;
        }
        void SetNext (Node* n){
            next=n;
        }
        void SetPre (Node* p){
            pre=p;
        }
};

int main(){
}