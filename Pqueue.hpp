#ifndef PQUEUE_HPP
#define PQUEUE_HPP
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Pqueue { 
private: 
    vector<pair<int, int>> heap;
    int parent(int i) {return (i - 1) / 2; }
    int left(int i ) {return 2 * i + 1; }
    int right(int i ) {return 2 * i + 2; }

    void heapifyInsert(int i) {
        while (i > 0 && heap[parent(i)].second > heap[i].second) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void minHeapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l].second < heap[smallest].second)
            smallest = l;
        if (r < heap.size() && heap[r].second < heap[smallest].second)
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }
public:
    Pqueue() = default;
    Pqueue(const Pqueue& other);
    Pqueue& operator=(const Pqueue& other);
    ~Pqueue() = default;
    int viewMin();
    void insert (int value, int key);
    int  extract_min();
    void decrease_key(int value, int target);
    
};



#endif
