//=========================================================
// WeightedGraph.hpp
// Son, Damian, Hoa
// Dec, 2024
// This is the header file with definitions of functions for the WeightedGraph class.
//=========================================================

#ifndef WEIGHTEDGRAPH_HPP
#define WEIGHTEDGRAPH_HPP

#include <vector>
#include <unordered_map>
#include <tuple>
#include <utility>

using namespace std;

class WeightedGraph
{
public:
    // Constructors and Destructor
    WeightedGraph();
    WeightedGraph(const WeightedGraph &copy);
    ~WeightedGraph();

    // Overleaded Operator
    WeightedGraph &operator=(const WeightedGraph &copy);

    // Function Prototypes
    void addEdge(size_t u, size_t v, double w);
    void removeEdge(size_t u, size_t v);
    bool edgeIn(size_t u, size_t v);
    void deleteVertex(size_t u);
    void addVertex(size_t u);
    // static WeightedGraph readFromSTDIN();
    unordered_map<size_t, pair<double, size_t>> Dijkstra(size_t source);
    double getWeight(size_t u, size_t v);


private:
    unordered_map<size_t, vector<pair<size_t, double>>> adjList;
};

#endif