#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int front, rear;
    string customers[SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Booking line is full. Please wait...\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        customers[rear] = name;
        cout << name << " joined the booking line.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No customers waiting.\n";
            return;
        }
        cout << customers[front] << " got the ticket.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers in line.\n";
            return;
        }
        cout << "\nCurrent waiting line: ";
        for (int i = front; i <= rear; i++) {
            cout << customers[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue ticketQueue;

    ticketQueue.enqueue("Ali");
    ticketQueue.enqueue("Sara");
    ticketQueue.enqueue("Ahmed");

    ticketQueue.display();

    ticketQueue.dequeue();  // Ali gets the ticket
    ticketQueue.display();

    ticketQueue.enqueue("Zara");
    ticketQueue.display();

    return 0;
}

