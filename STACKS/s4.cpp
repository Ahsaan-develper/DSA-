#include<iostream>
using namespace std;
class Stack{
    private:
        char arr[10];
        int top;
    public:
        Stack(){
            top = -1;
        }
        void push (char val){
            if (top  == 9){
             cout <<"Stack full"<<endl;
             return;
            }
           arr[++top]= val;
        }
        char pop (){
            if (top == -1){
                cout <<"Stack is empty "<<endl;
               return '\0';
            }else{
               return arr[top--];
            }
        }
        void display (){
           for (int i=top ; i>=0; i--){
            cout <<arr[i]<<" ";
           }
           cout <<endl;
        }
        bool isEmpty (){
            return top == -1;
        }
};
int main(){
    string su;
    cout <<"Enter string here "<<endl;
    cin>>su;
    Stack s;
   for (char ch : su){
    s.push(ch);
   }
   string reverse ="";
  
    while (!s.isEmpty())
    {
        reverse += s.pop();
    }
    if (su == reverse){
        cout <<" p";
    }else{
        cout <<"NO";
    }
    


   return 0;
}