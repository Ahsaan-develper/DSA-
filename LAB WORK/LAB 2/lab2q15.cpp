#include<iostream>
using namespace std;
void minFind(int* arr, int size){
    int* ptr = arr;
    int minVal= *ptr;
    for (int i=0  ;i<7 ;i++){
        ptr++;
        if (*ptr < minVal){
            minVal= *ptr;
        }
    }
cout <<"Min Value : "<<minVal<<endl;
    
}
int main(){
    int arr[7];
    for (int i=0 ;i<7;i++){
        cout <<"Enter num "<<endl;
        cin>> arr[i];
    }
    minFind(arr,7);
    return 0;
}