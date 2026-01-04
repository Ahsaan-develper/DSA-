#include <iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std ;

// ============================= Queue Node Class ===============================
class QueueNode {
public:
    string passengerName, CNIC, age, gender, seatNO;
    QueueNode* next;

    QueueNode(string p, string c, string a, string g, string s) {
        passengerName = p;
        CNIC = c;
        age = a;
        gender = g;
        seatNO = s;
        next = NULL;
    }
};

// ============================= Show Stations  Class============================== 
class ShowStaions {

    private :

    public:

    // Constructor 
        ShowStaions(){

        }
// --------------------------------Show Station Function------------------------------      
        void showStations (){

        }
};


// ============================= Admin Class============================== 
class Admin {
    private :
        string passengerName, seatNO,CNIC , age , gender ;
        string FilePassengerName, FileSeatNO,FileCNIC , FileAge , FileGender , line ;
    public:
    // Constructor 
        Admin(){

        }
 // --------------------------------Admin BookSeat Function-------------------------

        void bookSeat (){
            system("cls");
            cin.ignore();
            cout <<"1. passengerName \t 2.CNIC \t 3. Age \t 4.gender \t 5. SeatNo  "<<endl;
            cout<<"Enter PassengerName here "<<endl;
            getline(cin,passengerName);
             cout<<"Enter CNIC here "<<endl;
            getline(cin,CNIC);
             cout<<"Enter AGE here "<<endl;
            getline(cin,age);
             cout<<"Enter Gender here "<<endl;
            getline(cin,gender);
             cout<<"Enter Seat NO. here "<<endl;
            getline(cin,seatNO);
            ofstream outfile("BookSeat.txt",ios::app);
            if (!outfile){
                cout <<"Error : The Booking file is not open here !!!"<<endl;
                return;
            }else{
                outfile<<passengerName << '\t'<<CNIC << '\t' <<age <<'\t' <<gender <<'\t' <<seatNO<<endl;
            }
            outfile.close();
            cout<<"Seat is booked !!!"<<endl;
            cout << "\nPress Enter to return...";
            cin.ignore();
            cin.get();
        }
// --------------------------------Admin ViewSeat Function-------------------------
        void viewALLSeat() {

            ifstream infile("BookSeat.txt");
            if (!infile) {
                cout << "Error: Booking File is not open !!!" << endl;
                return;
            }

            // ----------- Queue pointers -----------
            QueueNode* front = NULL;
            QueueNode* rear = NULL;

            // ----------- Read file & enqueue -----------
            while (getline(infile, line)) {
                stringstream ss(line);
                getline(ss, passengerName, '\t');
                getline(ss, CNIC, '\t');
                getline(ss, age, '\t');
                getline(ss, gender, '\t');
                getline(ss, seatNO, '\t');

                QueueNode* newNode = new QueueNode(
                    passengerName, CNIC, age, gender, seatNO
                );

                if (front == NULL) {
                    front = rear = newNode;
                } else {
                    rear->next = newNode;
                    rear = newNode;
                }
            }
            infile.close();

            system("cls");

            cout << left << setw(20) << "1. Passenger"
                << setw(20) << "2. CNIC"
                << setw(10) << "3. Age"
                << setw(15) << "4. Gender"
                << setw(10) << "5. SeatNo" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;

            // ----------- Display queue -----------
            QueueNode* temp = front;
            while (temp != NULL) {
                cout << left << setw(20) << temp->passengerName
                    << setw(20) << temp->CNIC
                    << setw(10) << temp->age
                    << setw(15) << temp->gender
                    << setw(10) << temp->seatNO << endl;
                temp = temp->next;
            }

            // ----------- Free memory -----------
            while (front != NULL) {
                temp = front;
                front = front->next;
                delete temp;
            }

            cout << "\nPress Enter to return...";
            cin.ignore();
            cin.get();
        }

// --------------------------------Admin CancelSeat Function-----------------------
        void cancelSeat (){

        }
// --------------------------------Admin UpdateSeat Function-----------------------
        void updateSeat (){

        }

// --------------------------------Admin Panel Function-----------------------
        void adminPanel (){
            string choice ;
            int num ;
           do {
             cout <<"\t 1. Admin Book Seats "<<endl;
            cout <<"\t 2. Admin View Seats "<<endl;
            cout <<"\t 3. Admin Cancel Seats "<<endl;
            cout <<"\t 4. Admin Update Seats "<<endl;
            cout <<"\t 5. Exit Admin Panel "<<endl;
            cout <<"Please select an option ";
            num = atoi(choice.c_str());
            cin >> num;
                switch (num)
                {
                case 1 :
                    bookSeat();
                    break;
                case 2 :
                    viewALLSeat();
                    break;
                case 3 :
                    cancelSeat();
                    break;
                case 4 :
                    updateSeat();
                    break;
                case 5 :
                    cout <<"Good bye !!! From admin Panel"<<endl;
                    break;
                default:
                    cout <<"Invalid option Pleaase select again !"<<endl;
                    break;
                }
           }while(num !=5);
        }
};



// ============================= Admin Registration Class============================== 
class AdminRegistration {
    private:
        string choice ;
        int num ;
        string username, password , CNIC , Qualification ;
        bool isFound = false;
        string FileUsername , FileCNIC , FileQualification , FilePassword  , line ;
    public:

        AdminRegistration() {
            username = "";
            password = "";
            CNIC = "";
            Qualification = "";
        }
// --------------------------------Admin SignUp Function----------------------------

        void signUp (){
            system("cls");
            cout <<"---------------------Admin Sig Up --------------------"<<endl;
            cout <<"1. Enter Admin username \t 2. Entetr Admin CNIC  \t Enter Password of Admin \t Enter Qualification as BS , MS or PHD "<<endl;
            cout <<"Enter Username of Admin "<<endl;
            cin.ignore();
            getline(cin, username);
            cout << "Enter CNIC of Admin" <<endl;
            getline(cin,CNIC);
            cout <<"Enter Qualification of Admin "<<endl;
            getline(cin,Qualification);
            cout <<"Enter Password of Admin "<<endl;
            getline(cin,password);
            if(Qualification == "BS" || Qualification == "MS" || Qualification =="PHD" || Qualification == "bs" || Qualification == "ms" || Qualification == "phd"){
                ofstream outfile("AdminRegistration.txt" , ios::app);
                if (!outfile){
                    cout <<"Error ! Outfile is not open yet "<<endl;
                    return;
                }else{
                    system("cls");
                    outfile<<username <<"\t" <<CNIC << "\t" << Qualification << "\t" <<password<<endl;
                }
                outfile.close();
                cout <<"Admin is Registered !!!"<<endl;
                return;
            }else{
                cout <<"You enter wrong qualification "<<endl;
            }
        }
// --------------------------------Admin Login Function----------------------------
        void login (){
            system("cls");
            ifstream infile("AdminRegistration.txt");
            if (!infile){
                cout <<"Error : The file is not open !!!"<<endl;
                return;
            }else{
                cin.ignore();
                cout <<"Enter Username of Admin"<<endl;
                getline(cin ,username);
                cout <<"Enter CNIC of Admin"<<endl;
                getline(cin ,CNIC);
                cout <<"Enter Password of Admin"<<endl;
                getline(cin ,password);
                while (getline(infile,line))
                {
                    stringstream ss(line); 
                    getline(ss,FileUsername,'\t');
                    getline(ss,FileCNIC,'\t');
                    getline(ss,FileQualification,'\t');
                    getline(ss,FilePassword,'\t');

                    if (FileUsername == username && FileCNIC == CNIC  && FilePassword == password){
                        isFound = true;
                        break;
                    }
                }
                if (isFound){
                    cout <<"Admin Account is login welcome sir !!!"<<endl;
                    Admin admin ;
                    admin.adminPanel();
                }else{
                    cout <<"Please Enter correct account details" <<endl;
                    return ;
                }
                
                
            }
            infile.close();

        }

// --------------------------------Admin Registration Panel Function-----------------------
        void registrationPanel (){
            system("cls");
            do {
                 cout <<"\t 1. Admin Sign Up "<<endl;
                cout <<"\t 2. Admin Login "<<endl;
                cout <<"\t 3. Exit the Admin Authentication "<<endl;
                cout <<"Please select an option ";
                num = atoi(choice.c_str());
                cin >> num;
                switch (num)
                    {
                    case 1 :
                        signUp();
                        break;
                    case 2 :
                        login() ;
                        break;
                    case 3 :
                        cout <<"Good bye!!! From Admin Authentication Panel"<<endl;
                        break;
                    default:
                        cout <<"Invalid option Pleaase select again !"<<endl;
                        break;
                    }
            }while(num !=3);
        }
};



// ============================= Show List Class================================
class ShowList:Admin {
    private:

    public:
    // Constructor 
        ShowList(){

        }
// --------------------------------Show  List Function-----------------------
        void showList (){
        
        }
};
// --------------------------------Main Function-----------------------
int main(){
    string choice ;
    int num ;
        do {
        cout << "\n--- TRAIN RESERVATION SYSTEM ---\n";
        cout << "1. View Train Stations \n";
        cout << "2. Admin \n";
        cout << "3. View List\n";
        cout << "4. Exit the system \n";
        cout << "Please select an option  ";
        num = atoi(choice.c_str());
        cin >> num;   
            
            switch (num )
            {
            case 1 :{
                ShowStaions stations ;
                stations.showStations();
                break;
            }
                
            case 2: {
                AdminRegistration Adminregister ;
                Adminregister.registrationPanel();
                break;
            }  
            case 3 :{
                ShowList list ;
                list.showList();
            }
            case 4 :
                cout <<"Good bye!!! The system is exit !"<<endl;
                break;
            
            default:
                cout <<"Invalid number so enter correct number"<<endl;
                break;
            }
        }while(num != 4);
    return 0;
}