//=========================================================
// WeightedGraph.cpp
// Son, Damian, Hoa
// Dec, 2024
// This is the implementation file for the WeightedGraph class.
//=========================================================
#include "WeightedGraph.hpp"
#include "CustomExceptions.hpp"
#include "Pqueue.hpp"
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>


//=========================================================
// Default constructor for the WeightedGraph class
// Initializes an empty graph.
// Parameters: None
// Returns: None
//=========================================================
Graph::Graph(){}


//=========================================================
// Copy constructor for the Graph class
// Copies the adjacency list and sorted vector from another graph.
// Parameters: 
//   - copy: the Graph object to copy from.
// Returns: None
//=========================================================
Graph::Graph(const Graph& copy) {
    adjList = copy.adjList;
    sorted = copy.sorted;
}