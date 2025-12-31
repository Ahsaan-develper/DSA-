#include<iostream>
using namespace std;
int main(){
    int row,col;
    cout <<"Enter rows number ";
    cin>>row;
    cout <<"Enter col number";
    cin>>col;
    int arra [row][col];
    cout <<"Enter number  in array"<<endl;
    for (int i=0 ; i<row; i++){
        for (int j=0 ;j<col ; j++){
           cin>> arra[i][j];
        }
    }
    int sum =0;
    for (int i=0; i<row;i++){
        for (int j=0 ; j<col ; j++ ){
            sum += arra[i][j];
        }
    }
    cout <<"Sum is : "<<sum<<endl;
    float avg = float(sum) / (row* col);
    cout <<"Avg is : "<<avg<<endl;
    return 0;
}