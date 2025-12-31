#include <iostream>
using namespace std;

#define SIZE 10  // total array size

class TwoQueues {
private:
    int arr[SIZE];
    int front1, rear1;
    int front2, rear2;

public:
    TwoQueues() {
        front1 = rear1 = -1;
        front2 = rear2 = SIZE;
    }

    // Enqueue for Queue 1
    void enqueue1(int val) {
        if (rear1 + 1 == rear2) {
            cout << "Queue Overflow! No space available.\n";
            return;
        }
        if (front1 == -1)
            front1 = 0;
        rear1++;
        arr[rear1] = val;
        cout << "Inserted " << val << " in Queue 1\n";
    }

    // Enqueue for Queue 2
    void enqueue2(int val) {
        if (rear2 - 1 == rear1) {
            cout << "Queue Overflow! No space available.\n";
            return;
        }
        if (front2 == SIZE)
            front2 = SIZE - 1;
        rear2--;
        arr[rear2] = val;
        cout << "Inserted " << val << " in Queue 2\n";
    }

    // Dequeue from Queue 1
    void dequeue1() {
        if (front1 == -1 || front1 > rear1) {
            cout << "Queue 1 is empty!\n";
            return;
        }
        cout << "Removed " << arr[front1] << " from Queue 1\n";
        front1++;
        if (front1 > rear1)
            front1 = rear1 = -1;
    }

    // Dequeue from Queue 2
    void dequeue2() {
        if (front2 == SIZE || front2 < rear2) {
            cout << "Queue 2 is empty!\n";
            return;
        }
        cout << "Removed " << arr[front2] << " from Queue 2\n";
        front2--;
        if (front2 < rear2)
            front2 = rear2 = SIZE;
    }

    // Display both queues
    void display() {
        cout << "\nQueue 1: ";
        if (front1 == -1)
            cout << "Empty";
        else {
            for (int i = front1; i <= rear1; i++)
                cout << arr[i] << " ";
        }

        cout << "\nQueue 2: ";
        if (front2 == SIZE)
            cout << "Empty";
        else {
            for (int i = front2; i >= rear2; i--)
                cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    TwoQueues q;

    q.enqueue1(10);
    q.enqueue1(20);
    q.enqueue1(30);

    q.enqueue2(100);
    q.enqueue2(200);

    q.display();

    q.dequeue1();
    q.dequeue2();

    q.display();

    return 0;
}
