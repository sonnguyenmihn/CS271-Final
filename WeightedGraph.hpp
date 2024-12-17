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
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    bool edgeIn(int u, int v);
    void deleteVertex(int u);
    void addVertex(int u);
    static WeightedGraph readFromSTDIN();

private:
    unordered_map<double, vector<pair<double, double>>> adjList;
    unordered_map<double, pair<double, double>> Dijkstra(double source);
};

#endif