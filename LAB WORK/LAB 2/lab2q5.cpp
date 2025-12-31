#include<iostream>
using namespace std;
class Person {
    private:
        string name  ,CNIC;
        int age;

    public:
        Person (){
            name ="";
            age=0;
            CNIC="";
        }
        
        void setName(string n){
            name =n;
        }
         void setAge(int a){
            age =a;
            if (a<0 || a>130){
                
             age=0;
             cout <<"Please enter age less than 130 and greater than 0"<<endl;
            }else{
                age=a;
            }

        }
         void setCNIC(string c){
            if (c.length()==13){
                CNIC =c;
            }else{
                CNIC=" ";
                cout <<"Please enter lenght of CNIC 13 nor less neaither more"<<endl;
            }
        }
        string getName (){
            return name;
        }
         int getAge (){
            return age;
        }
         string getCNIC (){
            return CNIC;
        }

        void Print(){
            cout <<"Name :"<<name<<endl;
            cout <<"Age :"<<age<<endl;
            cout <<"CNIC :"<<CNIC<<endl;
        }

};
int main(){
    Person p1;
    p1.setName("Ahsan");
    p1.setAge(16);
    p1.setCNIC("1234567890123");
    p1.Print();
     Person p2;
    p2.setName("ali");
    p2.setAge(16);
    p2.setCNIC("12345890123");
    p2.Print();
    return 0;
}