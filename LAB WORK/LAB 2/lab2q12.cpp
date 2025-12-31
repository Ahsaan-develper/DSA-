#include<iostream>
using namespace std;
void Pointer (int* ptr){
cout <<"value : "<<*ptr<<endl;
}
int main(){
   int num =20;
   int* ptr =&num;
Pointer(ptr);
    return 0;
}