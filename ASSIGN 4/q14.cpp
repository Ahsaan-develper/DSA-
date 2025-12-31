#include<iostream>
using namespace std;
#define size 5
    class Queue {
        private:
            int front ,rear;
            int items[size];
        public:
            Queue(){
                front= -1;
                rear= -1;
            }
            bool isEmpty (){
                return (front == -1);
            }
            bool isFull (){
                return (rear== size -1 );
            }
            void enqueue (int val){
                if (isFull()){
                    cout <<"Queue is full"<<endl;
                    return;
                }else{
                    if (front== -1){
                        front++;
                    }
                    rear++;
                    items[rear]= val;
                }
            }
            void dequeue(){
                if (isEmpty()){
                    cout <<"Queue is empty "<<endl;
                    return;
                }else{
                    front++;
                    if (front> rear){
                        front = rear = -1;
                    }
                }
            }
            void display (){
                if (isEmpty()){
                    cout <<"Queue is empty "<<endl;
                    return;
                }else{
                    for (int i=front ; i<=rear ; i++){
                        cout <<items[i]<<" ";
                    }
                    cout <<endl;
                }
                
            }
    };
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}