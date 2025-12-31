#include<iostream>
using namespace std;
 void area(int* side){
        int area = *side * *side ;
        cout <<"Square area : "<<area<<endl;
    }
     void area(int* len,int* wid){
        int area = *len * *wid ;
        cout <<"Ractangle area : "<<area<<endl;
    }
     void area(float* rad){
        float area =3.14f * *rad * *rad ;
        cout <<"Square area : "<<area<<endl;
    }
int main(){
    int side,len,wid;
    float rad;
   cout <<"Enter side : "<<endl;
   cin>>side;
   cout <<"Enter len :"<<endl;
   cin>>len;
   cout <<"Enter wid :"<<endl;
   cin>>wid;
   cout <<"Enter radius :"<<endl;
   cin>>rad;
   area(&side);
   area(&len,&wid);
   area(&rad);

    return 0;
}