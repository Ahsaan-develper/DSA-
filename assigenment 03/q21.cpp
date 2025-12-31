#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
    queue<int> q1, q2;

public:
    // Push element into the stack
    void push(int x) {
        q2.push(x); // Step 1: Push new element into q2

        // Step 2: Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    // Pop top element
    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1.pop();
    }

    // Return top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q1.front();
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }

    // Display stack
    void display() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        queue<int> temp = q1;
        cout << "Stack (Top -> Bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop(); // Extra pop to show underflow

    return 0;
}
