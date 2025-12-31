#include<iostream>
using namespace std;
 int main(){
       int arr[10]= {1,2,3,4,5};
       int n= 5;
       int newElement =6;
       for ( int i= n-1 ; i>= 0 ; i--){
            arr[i +1] = arr[i];
       }
       n++;
       arr[0]=newElement;
        for ( int i=0 ; i<n ; i++){
        cout <<arr[i]<<" ";
    }
    return 0;
 }