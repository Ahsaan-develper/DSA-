#include<iostream>
using namespace std;
void BinaryToHexa (){
    int binary;
    int decimal=0 ,p=1;
    cout <<"Enter binary number to convert into hexa"<<endl;
    cin>>binary;
    while (binary >0){
        int digit = binary %10;
        decimal = decimal + (digit * p);
        p *= 2;
        binary /= 10;
    }
    char digits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string hex =" ";
    while (decimal>0){
        int digit= decimal %16;
        hex = hex + digits[digit];
        decimal /= 16;
    }
    cout <<"Hex is :\t"<<hex;
   
    return;
}
int main(){
BinaryToHexa();
    return 0;
}