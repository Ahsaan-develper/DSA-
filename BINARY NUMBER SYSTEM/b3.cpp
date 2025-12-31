#include<iostream>
using namespace std;
void DecimalToHexaDecimal(){
    int decimal;
    char digits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string hex =" ";
    cout <<"Enter Decimal to  convert it into HexaDecimal"<<endl;
    cin>>decimal;
    while (decimal >0)
    {
        int rem = decimal %16;
        hex =hex + digits[rem];
        decimal /= 16;
    }
    cout <<"HexaDecimal is :\t"<<hex<<endl;
    
}
int main(){
    DecimalToHexaDecimal();
    return 0;
}