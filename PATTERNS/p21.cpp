#include<iostream>
using namespace std;
int main(){
    for (int i=0 ; i<4 ; i++){
        for ( int j=0;j<4-i-1 ; j++){
            cout <<" ";
        }
        for (int k=1 ;k<i+1; k++){
            cout <<k;
        }
        for (int l=i+1 ; l>0;l--){
            cout <<l;
        }
        cout <<endl;
    }
    return 0;
}