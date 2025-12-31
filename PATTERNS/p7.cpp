#include <iostream>
using namespace std;
 int main(){
   char ch  ='A';
   int n=3;
   for (int i=0 ; i<4;i++){
    for (int j=0 ; j<4 ; j++){
        if (i == j+3-j){
            cout <<ch;
            ch++;
        }else{
            cout <<"*";
        }
    }
    cout <<endl;
   }
    return 0;
 }