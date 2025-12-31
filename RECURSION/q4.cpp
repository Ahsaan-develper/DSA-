#include<iostream>
using namespace std ;
bool isSorted (int arr[], int n){
    if (n==1 || n==0){
        return true ;
    }else {
        return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
    }
}
int main (){
    int arr[5]={1,2,10,4,5};
    cout <<isSorted(arr, 5);
    return 0;
}