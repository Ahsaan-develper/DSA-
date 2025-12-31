#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
    };
class Stack {
    private:
        Node* top;
    public:
        Stack(){
            top = NULL;
        }
        bool isEmpty (){
            return (top==NULL);
        }
        void push (int val){
            Node* newNode = new Node;
            newNode->data= val;
            newNode->next= top;
            top= newNode;
        }
        void pop (){
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        int peek (){
            if (!isEmpty()){
                return top->data;
            }else{
                return -1;
            }
        }
        void Display (){
            while (!isEmpty())
            {
                cout <<peek();
                pop();
            }
            cout <<endl;
        }
        void decimalToBinary (int dec){
            if (dec==0){
                cout <<"Binary is 0"<<endl;
            }else{
                while (dec>0)
                {
                    int rem =  dec% 2;
                    push(rem);
                    dec /= 2;
                }
            }
             cout <<"Binary ";
             Display();
        }
       

};
int main(){
    Stack st;
    int num ;
    cout <<"Enter decimal to gte binary"<<endl;
    cin>>num;
    st.decimalToBinary(num);
    
    return 0;
}