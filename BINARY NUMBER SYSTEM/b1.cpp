#include <iostream>
using namespace std;
    void DecimalToBinary(){
        int ans =0,p=1 ,decNum;
          cout <<"Enter number to convert it into binary form "<<endl;
          cin>>decNum;
          while (decNum >0)
          {
          int digit =  decNum %2 ;
          ans =ans + (p*digit);
          p =p*10;
          decNum /= 2;
          }
          cout <<"Binary is : "<<ans<<endl;
     return ;   
    }
int main(){
DecimalToBinary();
    return 0;
}