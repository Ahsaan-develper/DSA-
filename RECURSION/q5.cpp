#include<iostream>
using namespace std ;
int BinarySearch (int arr[] , int tar , int st , int end){
    if (st > end){
        return -1;
    }
    int mid = (st + end)/2;
    if (arr[mid] == tar){
        return tar;
    }else if (arr[mid] < tar){
        return BinarySearch(arr, tar, mid +1 , end );
    }else if (arr[mid] > tar){
        return BinarySearch(arr, tar, st ,  mid-1 );
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int tar = 2;
    cout <<BinarySearch(arr, tar,0 , 5)<<endl;
    return 0;
}