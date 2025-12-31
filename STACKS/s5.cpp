#include<iostream>
using namespace std;
class Stack {
    private:
        int arr[10];
        int top;
    public:
        Stack(){
            top=-1;
        }
        void push (char ch){
            if (top ==9){
                cout <<"Is full "<<endl;
                return;
            }else{
                arr[++top]=ch;
            }
        }
        void display (){
            for (int i =0 ; i<10; i++){
                cout <<arr[i]<<" ";
            }
        }
};
int main(){
    string str ;
    cout <<"Enter name "<<endl;
    cin>>str;
    for (char ch : str){

    }
    return 0;
}