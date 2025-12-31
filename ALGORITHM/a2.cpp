#include<iostream>
using namespace std;
int main(){
    int arr[]={1,4,2,3,7};
    int maxSum =arr[0];
    for (int i=0 ;i<5 ;i++){
        int sum =0;
        for (int j=i ; j<5 ;j++){
           sum += arr[j];
           maxSum = max(sum,maxSum);
        }
    }
    cout <<maxSum<<endl;
    return 0;
}