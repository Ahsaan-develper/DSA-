#include<iostream>
using namespace std;
int main(){
    
    for (int i=0 ; i<4 ; i++){
       for (int k=0 ; k<i ; k++){
        cout <<" ";
       }
        for (int j=0 ; j<4-i; j++){
            cout <<i+1;
        }
      
        cout <<endl;
    }
    return 0;
}