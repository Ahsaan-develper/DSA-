#include<iostream>
using namespace std;
class Queue {
    private:
        int* arr;
        int cap ,currSize;
        int f , r;
    public:
        Queue(int size){
             cap= size;
             arr =new int[cap];
            currSize=0;
            f=0;
            r=-1;
        }
        bool isEmpty (){
            return (currSize==0);
        }
        void enqueue(int data ){
            if (currSize == cap){
                cout <<"Queue is full "<<endl;
                return;
            }else{
                r = (r+1)% cap;
                arr[r]= data ;
                currSize++;
            }
        }   
        void dequeue(){
            if (isEmpty()){
                cout <<"Queue is empty "<<endl;
                return;
            }else{
                f= (f+1 )%cap;
                currSize--;
            }
        }
        void front (){
           if (isEmpty()){
                cout <<"Queue is empty "<<endl;
                return;
           }
            cout <<"Front is "<<arr[f]<<endl;
        }
        void print (){
            if (isEmpty()){
                cout <<"Queue is empty "<<endl;
                return;
            }
            else{
for (int i=0 ; i<cap; i++){
            cout << arr[i]<<" ";
          }
          cout <<endl;
            }
        }
};  
int main(){
    Queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.front();
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();

    return 0;
}