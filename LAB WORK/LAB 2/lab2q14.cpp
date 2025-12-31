#include <iostream>
using namespace std;

int main(){
    char arr[100];
    cout <<"Enter any type of msg"<<endl;
    cin.getline(arr,100);
    char* ptr =arr;
    int len=0;
    while(*ptr != '\0'){
        len++;
        ptr++;
    }
    cout <<"Lenght : "<<len<<endl;
   
     


    return 0;
}