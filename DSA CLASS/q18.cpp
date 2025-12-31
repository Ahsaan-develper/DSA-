#include<iostream>
using namespace std;
int main(){
   int arr[10]={1,2,3,4,5};
   int n , pos,size =5;
   cout <<"Enter new elemnt here "<<endl;
   cin>>n;
   cout <<"Enter position here "<<endl;
   cin>>pos;
   for (int i=size; i>pos; i--){
    arr[i]= arr[i-1];
   }
   arr[pos]=n;
   size++;
   cout <<"Numbers are : ";
   for (int i=0 ; i<size; i++){
    cout <<arr[i]<<" ";
   }
    return 0;
}