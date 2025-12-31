#include <iostream>
using namespace std;

class TwoStacks {
    int *arr;
    int size;
    int top1, top2;

public:
    // Constructor
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Push for stack1
    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow in Stack1\n";
        }
    }

    // Push for stack2
    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow in Stack2\n";
        }
    }

    // Pop from stack1
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack1 Underflow\n";
            return -1;
        }
    }

    // Pop from stack2
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack2 Underflow\n";
            return -1;
        }
    }

    // Display both stacks
    void display() {
        cout << "\nStack1 (Left -> Right): ";
        for (int i = 0; i <= top1; i++)
            cout << arr[i] << " ";

        cout << "\nStack2 (Right -> Left): ";
        for (int i = size - 1; i >= top2; i--)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    TwoStacks ts(10);

    ts.push1(5);
    ts.push1(10);
    ts.push2(20);
    ts.push2(30);

    ts.display();

    cout << "\nPopped from Stack1: " << ts.pop1();
    cout << "\nPopped from Stack2: " << ts.pop2();

    cout << "\n\nAfter popping:";
    ts.display();

    return 0;
}
