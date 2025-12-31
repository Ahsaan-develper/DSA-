#include<iostream>
using namespace std;
#define size 5
class ArrayQueue{
    private:
        int arr[size];
        int front ,rear;
    public:
        ArrayQueue(){
            front= -1 ;
            rear =-1;
        }
        void enqueue(int val){
            if (rear== size-1){
                cout <<"Queue is full"<<endl;
                return;
            }else{
                if (front == -1){
                    front++;
                }
                rear++;
                arr[rear] =  val;
            }
        }
        void dequeue(){
            if (front == -1 ){
                cout <<"Queue is empty "<<endl;
                return;
            }else{
                front++;
            }
        }
        void printArray(){
            if (front== -1 ){
                cout <<"Queue is empty"<<endl;
                return ;
            }else{
                for (int i=front; i<=rear; i++){
                    cout <<arr[i]<<" ";
                }
                cout <<endl;
            }
        }
        bool isEmpty (){
            return front ==-1;
        }
        int getFront (){
            if (front==-1){
                cout <<"Queue is empty "<<endl;
                return -1;
            }else{
                return arr[front];
            }
        }

};
int main(){
    ArrayQueue a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.printArray();
    cout <<a.getFront();
    return 0;
}