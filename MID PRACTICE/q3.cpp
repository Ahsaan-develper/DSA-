#include<iostream>
using namespace std;

int main(){
    int arr[5]= {1,2,3,4,5};
    int n=5;
    int arr2[5];
    int* ptr = arr;
    for (int i=0 ; i<n; i++){
        arr2[i] = *ptr + i;
    }
    for (int i=0 ; i<5; i++){
        cout <<arr2[i]<<" ";
    }
    return 0;
}