#include<iostream>
using namespace std;
int main(){
    string* name[3];
    for (int i=0;i<3;i++){
        name[i]= new string;
        cout <<"Enter name of student "<<i+1<<endl;
        cin>>*name[i];
    }
     cout << "\nStudent Names:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << ": " << *name[i] << endl;
    }
    for (int i = 0; i < 3; i++) {
        delete name[i];
    }
    return 0;
}