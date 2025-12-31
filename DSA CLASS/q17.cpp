#include<iostream>
using namespace std;
int main(){
    int n ;
    cout <<"Enter a number to insert it at beginning of array"<<endl;
    cin>>n;
    int arr[5]={2,3,4,5};
    int size = 4;
    for (int i=size ; i>0 ; i--){
        arr[i]= arr[i- 1];  
    }

    arr[0]=n;
    size++;
    for (int i=0 ; i<5; i++){
        cout <<arr[i];
    }
    return 0;
}