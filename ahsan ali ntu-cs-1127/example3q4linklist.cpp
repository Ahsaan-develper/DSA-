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
        char peek (){
            if (!isEmpty()){
                return top->data;
            }else{
                return '\0';
            }
        }
       
        bool isMatchPair (char open , char close){
            return (open =='(' && close==')'||open =='[' && close==']'||open =='{' && close=='}');
        }
       bool isBalance (string exp){
        for (char c : exp){
            if (c =='('|| c =='['|| c =='{'){
                push(c);
            }else if (c ==')'|| c ==']'|| c =='}' ){
                if (isEmpty() || !isMatchPair(peek(),c)){
                    return false;
                }
                pop();
            }
        }
        return isEmpty();
       }

};
int main(){
    Stack st;
   string exp;
    cout <<"Enter Symbal for check"<<endl;
    cin>>exp;
    if (st.isBalance(exp)){
        cout <<"Symbols are balance"<<endl;
    }else{
        cout <<"Not balance"<<endl;
    }
    
    return 0;
}