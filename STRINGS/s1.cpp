#include<iostream>
using namespace std;
int main(){
    char arr[12];
    
    cout <<"Enter somthing here!"<<endl;
    int count =0;
    cin.getline(arr,12);
    for (int i=0;arr[i] != '\0';i++ ){
        cout <<arr[i]<<" ";
        count++;
    }
    cout <<"Total char in arr : "<<count<<endl;
    return 0;
}