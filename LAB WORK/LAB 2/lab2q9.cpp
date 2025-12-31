#include<iostream>
using namespace std;

int main(){
    int num1 , num2;
cout <<"Enter first num "<<endl;
cin>>num1;
cout <<"Enter second Number"<<endl;
cin>>num2;
cout <<"---Before Swapping---"<<endl;
cout <<"num1 :"<<num1<<" num2 :"<<num2<<endl;
int* ptr1= &num1;
int* ptr2= &num2;
int temp = *ptr1;
*ptr1= *ptr2;
*ptr2=temp;

cout <<"---After Swaping---"<<endl;
cout <<"num1 :"<<num1<<" num2 :"<<num2<<endl;



    return 0;
}