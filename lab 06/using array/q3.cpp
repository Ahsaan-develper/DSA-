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
                cout <<val<<" Is added"<<endl;
            }
        }
        void dequeue(){
            if (front == -1 ){
                cout <<"Queue is empty "<<endl;
                return;
            }else{
                cout <<arr[front] <<" Is pop"<<endl;
                front++;
            }
        }
        void printArray(){
            if (front== -1 ){
                cout <<"Queue is empty"<<endl;
                return ;
            }else{
                cout <<"Values are : ";
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
   ArrayQueue ist ;
  int choice,num ;
  do {
      cout <<"Enter 1 for add value in queue"<<endl;
      cout <<"Enter 2 for delete value in queue"<<endl;
      cout <<"Enter 3 for print all values in queue"<<endl;
      cout <<"Enter 4 for system exit "<<endl;
      cin>>choice;
      switch (choice)
      {
    case 1:
        cout <<"Pleaase enter number to add "<<endl;
        cin>>num;
        ist.enqueue(num);
        break;
    case 2:
         ist.dequeue();
        break;
    case 3:
        ist.printArray();
        break;
    case 4:
       
       cout <<"Syestem is exit "<<endl;
        break;
      
      default:
        cout <<"Invalid  number or choice "<<endl;
        break;
}
  }while (choice!= 4);
return 0;
}