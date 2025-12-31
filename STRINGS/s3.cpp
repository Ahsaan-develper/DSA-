#include<iostream>
using namespace std;
int main(){
    char arr [100];
    cout <<"Enter any thing !"<<endl;
    cin.getline(arr,100);
    int start=0; 
    int len =0;
    for (int i=0 ; arr[i] != '\0';i++){
        len++;
}
int end = len-1;
   while (start < end){
    int temp = arr[start] ;
    arr[start]  = arr[end] ;
    arr[end] =temp;
    start++;
    end--;
   }
   cout <<arr<<endl;
   
   
    return 0;
}