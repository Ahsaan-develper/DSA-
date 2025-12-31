#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
    stack<int> s1, s2;

public:
    // Enqueue (push) element into the queue
    void enqueue(int x) {
        s1.push(x);
        cout << x << " enqueued to queue.\n";
    }

    // Dequeue (pop) element from the queue
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow! Queue is empty.\n";
            return;
        }

        // Move elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " dequeued from queue.\n";
        s2.pop();
    }

    // Get front element
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty.\n";
            return -1;
        }

        // Move elements if needed
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Display queue elements
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        // Temporary copy of stacks
        stack<int> temp1 = s1, temp2 = s2;

        // If s2 has elements, print them first
        cout << "Queue elements (Front → Rear): ";
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        // To print s1 elements in correct order
        stack<int> rev;
        while (!temp1.empty()) {
            rev.push(temp1.top());
            temp1.pop();
        }
        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Extra to show underflow

    return 0;
}
