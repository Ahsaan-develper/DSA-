#include<iostream>
using namespace std;
int main(){
    
    for (int i=0 ; i<4;i++){
        char ch ='A';
        for (int k=0 ;k<4; k++){
            cout <<ch;
            ch=ch+1;
        }   
        cout <<endl;
     }
    return 0;
}