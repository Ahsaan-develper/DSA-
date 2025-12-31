#include<iostream>
using namespace std;
int countEven (int* arr ,int size){
int count =0;
for (int i=0 ;i<size;i++){
    if (arr[i]%2==0){
        count++;
    }
}
return count;
}
int main(){
        int arr[8]={2,4,5,7,1,6,8,6};
        int size =sizeof(arr)/sizeof(arr[0]);
cout <<"The even numbers : "<< countEven(arr , size)<<endl;
    return 0;
}