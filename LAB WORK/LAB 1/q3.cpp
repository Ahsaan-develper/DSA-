#include<iostream>
using namespace std;
int main(){
    int num;
    cout <<"Enter n digits "<<endl;
    cin>>num;
    int sum =0;
    int rem=0;
    for (int i=0 ;num>0;i++){
        int digit = num %10;
        rem = rem *10 + digit;
        sum =sum +digit;
        num /=10;
    }
    cout <<"Sum is :"<<sum<<endl;
    for (int i=0 ;rem>0;i++){
        int digit = rem %10;
        cout<<digit <<",";
        rem /=10;
    }
    
    return 0;
}