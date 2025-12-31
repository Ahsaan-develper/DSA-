#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    int top;
    int arr[SIZE];

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top == SIZE - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    int num;
    Stack s;

    cout << "Enter a decimal number: ";
    cin >> num;

    int n = num;

    // Step 1: Divide number by 2 and push remainders onto stack
    while (n > 0) {
        int remainder = n % 2;
        s.push(remainder);
        n = n / 2;
    }

    // Step 2: Pop elements to get binary (reverse order)
    cout << "Binary equivalent of " << num << " is: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
