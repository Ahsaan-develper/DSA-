#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Enter word to check pallindrome or not"<<endl;
    getline(cin,s);
    int start =0, end = s.length()-1;
    string original = s;
    while (start<end){
        int temp = s[start];
        s[start]= s[end];
        s[end]= temp;
        start++;
        end--;
    }
    if (s == original){
        cout <<"Pallindrome"<<endl;
    }else{
        cout <<"Not pallindrom"<<endl;
    }
   
    
    return 0;
}