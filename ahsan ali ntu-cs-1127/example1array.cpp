#include<iostream>
using namespace std;

const int Size = 5;

class Stack {
    private:
        int StackArray[Size];
        int top ;
    public:
        Stack(){
            top = -1;
        }
         bool IsEmpty (){
           return (top==-1);   
        }
        bool IsFull(){
             return (top == Size - 1);
        }   

        int size (){
            return top + 1;
        }

        void Push (int val){
            if (IsFull()){
                cout <<"Stack is over flow  so not push "<<endl;
            }else{
                top ++;
                StackArray[top]= val;
                cout <<val<< " Value push in stack"<<endl;
            }
        }
        void Pop(){
            if (IsEmpty()){
                cout <<"Stack is empty "<<endl;
            }else{
                cout <<"Val pop : "<<StackArray[top]<<endl;
                top--;
            }
        }
       
        void Display(){
            cout <<"Elements in Stack are :";
            for (int i=top ;i>=0 ;i--){
                cout <<StackArray[i]<<" ";
            }
            cout <<endl;
        }
};
int main(){
    Stack stk;
    stk.Push(100);
    stk.Push(200);
    stk.Push(300);
    stk.Push(400);
    stk.Push(500);

    stk.Display();
    cout << "\nPoping..\n"; 
    stk.Pop();
    stk.Display();
    cout <<"System  puase"<<endl;

    return 0;
}