#include<iostream>
using namespace std;
void BinaryToDecimal(){
    int binary , ans=0,p=1; 
    cout <<"Enter binary to convert it into decimal"<<endl;
    cin>>binary;
    while (binary>0)
    {
       int digit = binary %10;
       ans = ans + (p* digit);
       p *= 2;
       binary /= 10;
    }
    cout <<"Decimal is :\t"<<ans<<endl;
    
    return;
}
int main(){
    BinaryToDecimal();
    return 0;
}