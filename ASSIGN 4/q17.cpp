#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (rear == SIZE - 1) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = val;
    }

    void displaySumAndAverage() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }

        int sum = 0;
        int count = 0;

        for (int i = front; i <= rear; i++) {
            sum += arr[i];
            count++;
        }

        float average = (float)sum / count;

        cout << "Sum of elements: " << sum << endl;
        cout << "Average of elements: " << average << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();
    q.displaySumAndAverage();

    return 0;
}
