#include<iostream>
using namespace std ;
void HexaToBinary(){
    int decimal =0,val,base=1;
    string hex ;
    cout <<"Enter hexa number to convert into binary"<<endl;
    cin>>hex;
    for (int i=hex.length()-1 ;i>=0 ;i--){
        char ch = hex[i];
        if (ch>= '0' && ch<='9'){
            val =  ch-'0';
        }else if (ch>='a' && ch<='f'){
            val= 10 + (ch-'a');
        }else if (ch>='A' && ch<='F'){
            val= 10 + (ch-'A');
        }
        decimal += val *base;
        base *= 16; 
    }
   int ans =0,p=1;
   while(decimal >0){
    int digit = decimal %2;
    ans += p*digit;
    p *=  10;
    decimal /=2;
   }
   cout <<"Binary is :\t"<<ans;
    return;
}
int main(){
HexaToBinary();
    return 0;
}