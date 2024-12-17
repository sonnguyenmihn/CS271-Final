#ifndef PQUEUE_HPP
#define PQUEUE_HPP
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Pqueue
{
private:
    vector<pair<double, double>> heap;
    double parent(double i) { return (i - 1) / 2; }
    double left(double i) { return 2 * i + 1; }
    double right(double i) { return 2 * i + 2; }

    void heapifyInsert(double i)
    {
        while (i > 0 && heap[parent(i)].second > heap[i].second)
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void minHeapify(double i)
    {
        double smallest = i;
        double l = left(i);
        double r = right(i);

        if (l < heap.size() && heap[l].second < heap[smallest].second)
            smallest = l;
        if (r < heap.size() && heap[r].second < heap[smallest].second)
            smallest = r;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
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
};

#endif
