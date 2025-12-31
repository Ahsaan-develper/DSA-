// Array_MaxHeap.cpp
#include <iostream>
using namespace std;

class MaxHeap {
    int arr[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int val) {
        size++;
        int i = size;
        arr[i] = val;

        // heapify up
        while (i > 1) {
            int parent = i / 2;
            if (arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                break;
            }
        }
    }


    void print() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(50);
    h.insert(20);
    h.insert(30);
    h.insert(10);

    cout << "Max Heap:\n";
    h.print();

 
    return 0;
}
