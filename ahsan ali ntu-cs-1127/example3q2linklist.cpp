#include<iostream>
#include<cctype>
using namespace std;
class Node {
    public:
        int data ;
        Node* next ;
};
class Stack {
    private:
        Node* top ;
    public:
        Stack(){
            top= NULL;
        }
        bool isEmpty (){
            return (top ==NULL);
        }
        void push (int val){
            Node* newNode = new Node;
            newNode->data= val;
            newNode->next=top;
            top = newNode;
        }
        void pop(){
            Node* temp = top;
            top= top->next;
            delete temp;
        }
        int peek (){
            if (!isEmpty()){
                return top->data;
            }else{
                return -1;
            }
        }
};

    bool isOperator (char c){
        return (c=='-'|| c=='+'|| c=='*' || c=='^' ||c=='/');
    }

    int evaluatePostfix (string postfix){
        Stack st;
        for (char c : postfix){
            if (isdigit(c)){
                st.push(c -'0');
            }else if (isOperator(c)){
                int val2=  st.peek(); st.pop();
                int val1=  st.peek(); st.pop();
                
                int result =0;
                switch (c)
                {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '^':
                    result = 1;
                    for ( int i=0 ; i<val2 ; i++){
                        result *= val1;
                    }
                    break;
                default:
                    break;
                }
                st.push(result);
            }
        }
        return st.peek();
    }
int main(){
    string postfix;
    cout << "Enter postfix expression (digits only, e.g., 53*82/+4-): ";
    cin >> postfix;

    int  result =evaluatePostfix(postfix);

    cout << "Result = " << result << endl;
    return 0;
}