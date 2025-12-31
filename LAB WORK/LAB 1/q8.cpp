#include<iostream>
using namespace std;
int main(){
    int table,limit;
    cout <<"Enter table number "<<endl;
    cin>>table;
    cout <<"Enter limit"<<endl;
    cin>>limit;
    for (int i=1  ; i<=limit;i++){
        cout <<table <<" x "<<i<<" = "<<table *i<<endl;
    }
    return 0;
}