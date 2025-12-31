#include<iostream>
using namespace std;
int pointerSum(int* n1 , int* n2){
    return *n1 + *n2;
}
int main(){
        int num1 , num2;
cout <<"Enter first num "<<endl;
cin>>num1;
cout <<"Enter second Number"<<endl;
cin>>num2;
int sum =pointerSum(&num1,&num2);
cout <<"sum : "<<sum<<endl;
    return 0;
}