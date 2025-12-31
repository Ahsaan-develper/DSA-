#include <iostream>
using namespace std;
void change (int* ptr){
      *ptr = 20;
}
void Num(int &n){
    n=20;
}
int main(){

//     int price = 100;
// int* p = &price;
// int** p1 = &p;
// cout<<"price "<< price<<endl;
// cout<<"price address"<< &price<<endl;
// cout<<"pointer have price address "<<p<<endl;
// cout<<"pointer have  address"<<&p<<endl;
// cout<<"pointer value"<<*p<<endl;
// cout <<"P Pointer have price addres store in pointer address"<<*p1<<endl;
// cout <<"p pointer have p addrsss"<<p1<<endl;
// cout<<"p pointer have own adress"<<&p1<<endl;
// cout <<"de refrenceto price "<<**p1<<endl;

// int* ptr = NULL;
// cout <<"ptr addresss"<<&ptr<<endl;


cout<<"--------------------------------------";
int a= 10;
change(&a);
cout<<"value of a :" <<a<<endl;

cout<<"--------------------------------"<<endl;
int num=10;
    Num(num);
    cout <<"Num is :"<<num<<endl;

int arr[] = {1,2,3,4,5};
cout<<"array"<<*(arr+2)<<endl;

// INCREment or deceament
int b = 10;
int* ptr = &b;
cout<<"------------"<<endl;
cout<<ptr<<endl;
ptr++;
cout<<ptr<<endl;
ptr--;
cout<<ptr<<endl;
cout <<"---------------------------"<<endl;
int p = 10;
int* ptr1 = &p;
cout<<ptr1<<endl;
ptr1=ptr1 + 2;
cout<<ptr1<<endl;



    return 0;
}
