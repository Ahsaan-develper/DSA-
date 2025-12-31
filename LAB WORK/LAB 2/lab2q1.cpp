#include<iostream>
using namespace std;
string GetChoice (){
    string shape;
    cout <<"Enter shape e.g Circle , Ractangle or Square"<<endl;
    cin>>shape;
    if (shape == "square" || shape == "Square"){
        return shape;
    }else if(shape == "Circle" || shape == "circle"){
        return shape;
    }else if (shape == "ractangle" || shape == "ractangle"){
        return shape;
    }else{
        cout <<"Please enter Circle ,Ractangle or Square"<<endl;
    }
}
void CalculateArea (string shape){
    int rad,len,wid;
     if (shape == "square" || shape == "Square"){
        cout <<"Enter radius here "<<endl;
        cin>>rad;
        cout <<"Square :\t"<<rad *rad<<endl;
    }else if (shape == "Circle" || shape == "circle"){
        cout <<"Enter radius here "<<endl;
        cin>>rad;
        cout <<"Circle :\t"<<3.14*rad *rad<<endl;
       
    }else if (shape == "Ractangle" || shape == "ractangle"){
        cout <<"Enter Length here "<<endl;
        cin>>len;
        cout <<"Enter width here "<<endl;
        cin>>wid;
        cout <<"Ractangle :\t"<<len *wid<<endl;
    }
}
int main(){
    string shape = GetChoice();
    CalculateArea(shape);

    return 0;
}