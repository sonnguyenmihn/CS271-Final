#include "Pqueue.hpp"
#include <algorithm>
#include <utility>
#include "CustomExceptions.hpp"
using namespace std;

Pqueue::Pqueue(const Pqueue& other) {
    heap = other.heap;
}

Pqueue& Pqueue::operator=(const Pqueue& other) {
    if (this != &other) {
        heap = other.heap;
    }

    return *this;
}

int Pqueue::viewMin() {
    if (heap.size() < 1) {
        throw ElementException("Heap Underflow");
    }
    
    else
        return heap[0].first;
}

void Pqueue::insert(int value, int key) {
    pair new_element = make_pair(value, key);
    heap.push_back(new_element);
    heapifyInsert(heap.size() - 1);
}



int Pqueue::extract_min() {
    if (heap.size() < 1) {
        throw ElementException("Heap Underflow");
    }
    int min = heap[0].first;
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    minHeapify(0);
    
    return min;
}

void Pqueue::decrease_key(int value, int target) {
    auto it = find(heap.begin(), heap.end(), value);
    if (it == heap.end()) {
        throw ElementException("Value does not exist in heap");
    }

    int i = distance(heap.begin(), it);
    if (heap[i].second < target) {
        throw KeyException("Target key is larger than current key");
    }

    heap[i].second = target;
    if (i > 0) {    //dont need to heapify up for top elements
        heapifyInsert(i);
    }
}







