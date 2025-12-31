#include<iostream>
using namespace std;
int main(){
    string s ;
    cout <<"Enter any word here "<<endl;
    getline(cin,s);
    for (int i=s.length();i>=0; i--){
        cout <<s[i];
    }

    return 0;
}