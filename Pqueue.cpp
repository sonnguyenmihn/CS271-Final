//=========================================================
// Pqueue.hpp
// Son, Damian, Hoa
// Dec, 2024
// This is the implementation file (min) Pqueue class.
//=========================================================
#include "Pqueue.hpp"
#include <algorithm>
#include <utility>
#include "CustomExceptions.hpp"
using namespace std;

//=============================
// Copy Constructor
// Parameters: const Pqueue& other
// RETURN: Creates a copy of the provided Pqueue object
//=============================
Pqueue::Pqueue(const Pqueue &other)
{
    heap = other.heap;
}

//=============================
// Pqueue::operator=
// Parameters: const Pqueue& other
// RETURN: Reference to the current Pqueue object after assignment
//=============================
Pqueue &Pqueue::operator=(const Pqueue &other)
{
    if (this != &other)
    {
        heap = other.heap;
    }
    return *this;
}

//=============================
// Pqueue::viewMin
// Parameters: None
// RETURN: The minimum value in the heap (size_t)
// Throws an exception if the heap is empty
//=============================
size_t Pqueue::viewMin()
{
    if (heap.size() < 1)
    {
        throw ElementException("Heap Underflow");
    }
    else
    {
        return heap[0].first;
    }
}

//=============================
// Pqueue::insert
// Parameters: size_t value - the value to insert, size_t key - the priority of the value
// RETURN: Adds a new element to the heap and maintains heap order
//=============================
void Pqueue::insert(size_t value, double key)
{
    pair new_element = make_pair(value, key);
    heap.push_back(new_element);
    heapifyInsert(heap.size() - 1);
}

//=============================
// Pqueue::extract_min
// Parameters: None
// RETURN: The minimum value in the heap (size_t) and removes it
// Throws an exception if the heap is empty
//=============================
size_t Pqueue::extract_min()
{
    if (heap.size() < 1)
    {
        throw ElementException("Heap Underflow");
    }
    size_t min = heap[0].first;
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    minHeapify(0);
    return min;
}

//=============================
// Pqueue::decrease_key
// Parameters: size_t value - the value whose key to decrease,
//             size_t target - the new (smaller) key value
// RETURN: Updates the key of the specified value and maintains heap order
// Throws exceptions if the value is not found or the target key is bigger
//=============================
void Pqueue::decrease_key(size_t value, double target)
{
    int index = -1;
    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i].first == value)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        throw ElementException("Value does not exist in heap");
    }

    if (heap[index].second < target)
    {
        throw KeyException("Target key is larger than current key");
    }

    heap[index].second = target;
    if (index > 0)
    { 
        // Don't need to heapify up for top elements
        heapifyInsert(index);
    }
}

//=============================
// This function checks if the pq is empty
// Parameters: None
// RETURN: bool
//=============================
bool Pqueue::isEmpty()
{
    return heap.empty();
}
