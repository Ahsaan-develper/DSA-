#include <iostream>
using namespace std;

void HexaDeccimalToDecimal() {
    int decimal = 0;   // final answer
    int base = 1;      // starts at 16^0
    string hexa;

    cout << "Enter Hexa number to convert it into decimal: ";
    cin >> hexa;

    // process from rightmost digit to leftmost
    for (int i = hexa.length() - 1; i >= 0; i--) {
        char ch = hexa[i];
        int value;

        if (ch >= '0' && ch <= '9') {
            value = ch - '0';  // e.g. '3' → 3
        } else if (ch >= 'a' && ch <= 'f') {
            value = 10 + (ch - 'a'); // e.g. 'a' → 10
        } else if (ch >= 'A' && ch <= 'F') {
            value = 10 + (ch - 'A'); // e.g. 'B' → 11
        } else {
            cout << "Invalid hex digit: " << ch << endl;
            return;
        }

        decimal += value * base; // add digit × base
        base *= 16;              // move to next power of 16
    }

    cout << "Decimal = " << decimal << endl;
}

int main() {
    HexaDeccimalToDecimal();
    return 0;
}
