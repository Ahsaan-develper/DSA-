#include<iostream>
using namespace std;
int main(){
    int arr1[5]={1,2,3,4,5};
    int arr2[5];
    int* ptr1=arr1 ;
    int* ptr2=arr2;
    for (int i=0 ;i<5 ; i++){
        *ptr2= *ptr1;
        ptr1++;
        ptr2++;
    }
    cout <<"Copy arra : ";
    for (int i=0 ; i<5 ;i++){
        cout <<arr2[i]<<" ";
    }

    return 0;
}