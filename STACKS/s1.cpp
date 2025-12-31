#include<iostream>
using namespace std;
class Stack {
    private:
        int arr [5];
        int top;
    public:
            Stack(){
                top = -1;
            }
             void push (int val){
                if (top==-1){
                    top++;
                }
                arr[++top] = val;
             }
             void pop (){
                if (top == -1){
                    cout <<"Stack is empty "<<endl;
                    return;
                }else{
                    arr[top--];
                }
             }
             void display (){
                for (int i=top; i>0; i--){
                    cout <<arr[i]<<" ";
                }
                cout <<endl;
             }
};
int main(){
        Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.display();
        s.pop();
        s.display();
    return 0;
}