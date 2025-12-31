#include<iostream>
using namespace std;
class Person {
    private:
        string name  ,CNIC;
        int age;

    public:
        Person (string n, int a ,string c){
            name =n;
            age=a;
            CNIC=c;
        }
    
        void Print (){
            cout <<"Name :\t"<<name<<endl;
            cout <<"Age :\t"<<age<<endl;
            cout <<"CNIC :\t"<<CNIC<<endl;
        }
    
    

};
int main(){
    Person p("ahsan",10,"123456");
    p.Print();
    return 0;
}