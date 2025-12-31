#include<iostream>
#include<stack>
using namespace std;

bool isPallindrome(string str){
    stack<char> s;
    for (int i=0 ; i<str.length(); i++){
            s.push(str[i]);
    }

    for (int i=0 ; i<str.length(); i++){
        if (str[i] != s.top()){
            return false;
        }
        s.pop();
    }
    return true;
}   
int main(){
    string str ;
    cout <<"Enter string here "<<endl;
    cin>>str;
    if (isPallindrome(str)){
         cout << " The string is a palindrome." << endl;
    }else{
        cout << " The string is NOT a palindrome." << endl;
    }

    return 0;
}