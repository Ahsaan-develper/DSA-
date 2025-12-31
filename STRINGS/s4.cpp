#include <iostream>
using namespace std;
int main(){
    string s ;
    cout <<"Enter something here!"<<endl;
    getline(cin,s);
    cout <<"----Before reversing----"<<endl;
    cout <<s<<endl;
    cout <<"----After reversing----"<<endl;
    for (int i=s.length()-1; i>=0;i--){
        cout <<s[i];
    }
    return 0;
}