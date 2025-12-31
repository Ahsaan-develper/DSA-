#include <iostream>
using namespace std;
 int main(){
    int num;
    cout <<"Enter three digit number "<<endl;
    cin>>num;
    if (num<100 || num > 999){
      cout <<"Please enter only three digits"<<endl;
      return 0;
    }
    int rev=0;
    cout <<"-----Before reversing -----: \t"<<num<<endl;
    while (num >0)
    {
        int digit = num %10;
        rev = rev *10 + digit;
        num /= 10;
    }
      cout <<"-----after reversing -----: \t"<<rev<<endl;
    return 0;
 }