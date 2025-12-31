#include<iostream>
using namespace std;
int main(){
    string s ;
    cout <<"Enter any line to cout words "<<endl;
    getline(cin,s);
    int words =0;
    bool inWord=false;
    for (int i=0; i<s.length();i++){
        if (s[i] !=' ' && !inWord ){
            words ++;
            inWord = true;
        }else if (s[i] == ' '){
            inWord = false;
        }

    }
    cout <<"Number of words are : "<<words<<endl;
    return 0;
}