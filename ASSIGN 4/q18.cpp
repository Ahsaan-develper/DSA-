#include <iostream>
#include <queue>     // for priority_queue
using namespace std;

int main() {
    // Declare a max-heap priority queue (highest value has highest priority)
    priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(50);

    cout << "Priority Queue elements (in order of priority):" << endl;

    // Display and remove elements (highest first)
    while (!pq.empty()) {
        cout << pq.top() << " ";  // top() gives the highest priority element
        pq.pop();                 // remove it
    }

    cout << endl;

    return 0;
}
