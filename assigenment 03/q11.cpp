    #include<iostream>
    using namespace std;

    #define MAX 5

    class Stack {
        private:
            int arr[MAX];
            int top;
        public:
            Stack(){
                top=-1;
            }
            void push(int val){
                if (top==MAX -1 ){
                    cout <<"Stack overflow cannont push "<<val<<endl;
                }else{
                    top++;
                    arr[top] = val;
                    cout <<"Value push :  "<<val<<endl;
                }
            }
            
            void pop (){
                if (top== -1){
                    cout <<"Stack underflow no element to remove"<<endl;
                }else{
                    cout <<arr[top]<<" pop from stack"<<endl;
                    top--;
                }
            }

            void Display (){
                if (top== -1 ){
                    cout <<"Stack is empty "<<endl;
                }else{
                    cout <<"Stack elements :";
                    for (int i=top ; i>=0; i--){
                        cout <<arr[i]<<" ";
                    }
                    cout <<endl;
                }
            }
    };
    int main(){
        Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.Display();
        cout <<" pop elemnt "<<endl;
        s.pop();
        s.Display();
        return 0;
    }