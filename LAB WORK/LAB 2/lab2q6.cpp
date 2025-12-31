#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    // Constructor
    Distance(int f = 0, float i = 0.0) {
        feet = f;
        inches = i;
        normalize();  // make sure inches < 12
    }

    // Function to normalize inches into feet
    void normalize() {
        if (inches >= 12) {
            int extraFeet = int(inches / 12);
            feet += extraFeet;
            inches = inches - (extraFeet * 12);
        }
    }

    // Function to display distance
    void Display() {
        cout << "Feet: " << feet << ", Inches: " << inches << endl;
    }

    // Function to add two distances
     Distance addDistance(Distance d) {
        Distance temp;
        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;

        // Normalize inches in temp, not in 'this'
        if (temp.inches >= 12) {
            int extraFeet = (int)(temp.inches / 12);
            temp.feet += extraFeet;
            temp.inches = temp.inches - (extraFeet * 12);
        }
        return temp;
    }
};

int main() {
    Distance d1(12, 14.5);   // 12 feet 14.5 inches
    Distance d2(10, 9.5);    // 10 feet 9.5 inches

    Distance d3 = d1.addDistance(d2); // add d1 + d2

    cout << "First distance: ";
    d1.Display();

    cout << "Second distance: ";
    d2.Display();

    cout << "Sum of distances: ";
    d3.Display();

    return 0;
}
