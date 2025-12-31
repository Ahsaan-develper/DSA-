#include<iostream>
using namespace std;
class Student_Detail{
    private:
        string roll_No,name;
        int marks[3];
    
        public:
            void AddStudents(){
                cout <<"Enter student Roll_No"<<endl;
                cin>>roll_No;
                cout <<"Enter student name"<<endl;
                cin>>name;
                for (int i=0 ;i<3;i++){
                    cout <<"Enter marks in subject "<<i+1<<endl;
                    cin>>marks[i];
                }

            }
            bool FailedStudents (){
                int count=0;
                for (int i=0; i<3 ;i++){
                    if (marks[i]<40){
                        count++;
                    }
                }
                return count;
            
            }
            void PrintStudent(){
                cout <<"Roll NO is : \t"<<roll_No<<endl;
                cout<<"Name is : \t"<<name<<endl;
            }

};
int main(){
   
Student_Detail students[25];
    for (int i=0 ;i<25 ;i++){
        cout <<"Enter details of students "<<i+1<<endl;
        students[i].AddStudents();
    }
    cout <<"Students who failed in more than one subject"<<endl;
    for (int i=0 ;i<25;i++){
        if (students[i].FailedStudents()){
            students[i].PrintStudent();
        }
    }
    return 0;
}