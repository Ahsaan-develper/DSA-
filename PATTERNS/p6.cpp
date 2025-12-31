#include <iostream>
using namespace std;
 int main(){
    char ch ='D';
    for (int i=0 ; i<4 ; i++){
        for (int k=0 ; k<4; k++){
            if (k ==4-i-1 ){
                
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