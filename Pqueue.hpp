#ifndef PQUEUE_HPP
#define PQUEUE_HPP
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Pqueue { 
private: 
    // Underlying heap structure to implement the priority queue
    vector<pair<double, double>> heap;

    //=============================
    // parent
    // Parameters: double i - index of a node
    // RETURN: Index of the parent node of the given node
    // Description: Used to navigate upwards in the heap
    //=============================
    double parent(double i) { return (i - 1) / 2; }

    //=============================
    // left
    // Parameters: double i - index of a node
    // RETURN: Index of the left child of the given node
    // Description: Used to navigate to the left child in the heap
    //=============================
    double left(double i) { return 2 * i + 1; }

    //=============================
    // right
    // Parameters: double i - index of a node
    // RETURN: Index of the right child of the given node
    // Description: Used to navigate to the right child in the heap
    //=============================
    double right(double i) { return 2 * i + 2; }

    //=============================
    // heapifyInsert
    // Parameters: double i - the index of the node to heapify upwards
    // RETURN: Adjusts the position of the node upwards in the heap
    // Description: Ensures the min-heap property is madoubleained after insertion
    //=============================
    void heapifyInsert(double i) {
        // While the current node violates the min-heap property with its parent
        while (i > 0 && heap[parent(i)].second > heap[i].second) {
            swap(heap[parent(i)], heap[i]);  // Swap with the parent node
            i = parent(i);                   // Move to the parent's index
        }
    }

    //=============================
    // minHeapify
    // Parameters: double i - the index of the node to heapify downwards
    // RETURN: Adjusts the position of the node downwards in the heap
    // Description: Ensures the min-heap property is maintained after extracting the minimum
    //=============================
    void minHeapify(double i) {
        double smallest = i;       // Assume the current node is the smallest
        double l = left(i);        // Index of the left child
        double r = right(i);       // Index of the right child

        // Compare with the left child
        if (l < heap.size() && heap[l].second < heap[smallest].second)
            smallest = l;

        // Compare with the right child
        if (r < heap.size() && heap[r].second < heap[smallest].second)
            smallest = r;

        // If the smallest node is not the current node, swap and continue
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);  // Recursive call to heapify further down
        }
    }

public:
    Pqueue() = default;
    Pqueue(const Pqueue &other);
    Pqueue &operator=(const Pqueue &other);
    ~Pqueue() = default;
    double viewMin();
    void insert(double value, double key);
    double extract_min();
    void decrease_key(double value, double target);
    bool isEmpty();
};

#endif
