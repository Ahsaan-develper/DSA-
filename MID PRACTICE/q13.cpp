#include<iostream>
using namespace std;
class Node {
    public:
        char data;
        Node* next;
};
class stack {
   private:
        Node* top ;
    public:
        stack (){
            top= NULL;
        }
        void push (char ch){
            Node* newNode= new Node;
            newNode->next=NULL;
            newNode->data= ch;
            top=newNode; 
        }
        char pop (){
            if (top==NULL){
                cout <<"Under flow"<<endl;
                return '\0';
            }else{
                    Node* temp = top;
                    char ch = temp ->data;
                    top = top ->next;
                    delete temp;
                    return ch ;
            }
        }
        char peek (){
            if (top == NULL){
                cout <<"Stack us empty"<<endl;
                return '\0';
            }else{
                return top ->data;
            }
        }
        bool isEmpty (){
            return top==NULL;
        }
        bool isOPerator (char ch ){
            return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
        }
        int Precedance (char op ){
            if (op=='^'){
                return 3;
            }else if (op =='/'|| op =='*'){
                return 2 ;
            }else if (op =='-'|| op =='+'){
                return 1 ;
            }
        }
        string InfixToPostix (string infix){
            stack s;
            string postfix ="";
            for (int i=0 ; i<infix.length();i++){
                char ch = infix[i];
                if (isalnum(ch)){
                    postfix +=ch;

                }
                else if (ch=='('){
                        s.push(ch);
                }else if (ch ==')'){
                    while (!s.isEmpty() && s.peek() != '(')
                    {
                        postfix += s.pop();
                    }
                    s.pop();
                }else if (isOPerator(ch)){
                    while (!s.isEmpty() && Precedance(s.peek()) >= Precedance (ch))
                    {
                      postfix += s.pop();     
                  }
                        s.push(ch);
                }
            }
            while (!s.isEmpty())
            {
                postfix += s.pop();
            }   
            return postfix;
        }  

};
int main(){
   
    return 0;
}