#include<iostream>
using namespace std;
int  main(){
    int arr[4]={1,2,3,4};
    // max number in array 
    int max =arr[0];
    int min = arr[0];
    for (int i=0 ; i<4 ; i++){
        if (arr[i]>max){
            max=arr[i];
        }
        if (arr[i]<min){
            min= arr[i];
        }
    }
    cout <<"Max numbber is : "<<max<<endl;
    cout <<"Min numbber is : "<<min<<endl;
    return  0;
}