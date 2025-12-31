#include<iostream>
#include<list>
using namespace std;
class Stack {
    private:
        list<int> li;
    public:
        void push (int val){
            li.push_front(val);
        }
        void pop (){
            li.pop_front();
        }
        int top (){
            return li.front();
        }
        bool isEmpty (){
            return li.size()==0;
        }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.isEmpty())
    {
        cout <<s.top()<<" ";
        s.pop();
    }
    cout <<endl;
    
    return 0;
}