// File: 20_MinHeap.cpp
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap; // 0-based
    void siftUp(int i) {
        while (i > 0) {
            int p = (i-1)/2;
            if (heap[p] <= heap[i]) break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }
    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int l = 2*i + 1, r = 2*i + 2, smallest = i;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }
public:
    void insert(int x) { heap.push_back(x); siftUp(heap.size()-1); }
    int getMin() const { if (heap.empty()) throw runtime_error("empty"); return heap[0]; }
    void deleteMin() {
        if (heap.empty()) throw runtime_error("empty");
        heap[0] = heap.back(); heap.pop_back();
        if (!heap.empty()) siftDown(0);
    }
    bool empty() const { return heap.empty(); }
    void print() const {
        for (int v: heap) cout << v << " ";
        cout << "\n";
    }
};

int main() {
    MinHeap h;
    h.insert(5); h.insert(3); h.insert(8); h.insert(1);
    cout << "Heap array: "; h.print();
    cout << "Min: " << h.getMin() << "\n";
    h.deleteMin();
    cout << "After deleteMin, heap: "; h.print();
    return 0;
}
