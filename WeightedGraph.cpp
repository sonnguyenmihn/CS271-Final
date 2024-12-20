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
#include <limits>

//=========================================================
// Default constructor for the WeightedGraph class
// Initializes an empty graph.
// Parameters: None
// Returns: None
//=========================================================
WeightedGraph::WeightedGraph() {}

//=========================================================
// Copy constructor for the WeightedGraph class
// Copies the adjacency list and sorted vector from another graph.
// Parameters:
//   - copy: the WeightedGraph object to copy from.
// Returns: None
//=========================================================
WeightedGraph::WeightedGraph(const WeightedGraph &copy)
{
    adjList = copy.adjList;
}

//=========================================================
// Destructor for the WeightedGraph class
// Cleans up any allocated resources (default behavior).
// Parameters: None
// Returns: None
//=========================================================
WeightedGraph::~WeightedGraph() {}

//=========================================================
// Overloaded assignment operator for the WeightedGraph class
// Assigns the values of one graph to another.
// Parameters:
//   - copy: the WeightedGraph object to assign from.
// Returns: A reference to the assigned Graph.
//=========================================================
WeightedGraph &WeightedGraph::operator=(const WeightedGraph &copy)
{
    if (this != &copy)
    {
        adjList = copy.adjList;
    }
    return *this;
}

//=========================================================
// Adds a directed edge with a positive weight between two vertices.
// If the edge already exists or if one of the vertices does not exist, the function does nothing.
// Parameters:
//   - u: source vertex.
//   - v: destination vertex.
//   - w: weight
// Returns: None
//=========================================================
void WeightedGraph::addEdge(size_t u, size_t v, double w)
{
    if (adjList.find(u) == adjList.end() || adjList.find(v) == adjList.end())
    {
        throw vertex_exception("One or both vertices do not exist.");
    }
    if (edgeIn(u, v))
    {
        return;
    }
    // Check if both u and v exist
    if (adjList.find(u) != adjList.end() && adjList.find(v) != adjList.end())
    {
        adjList[u].push_back(make_pair(v, w));
    }
}

//=========================================================
// Removes a directed edge between two vertices.
// Throws an exception if the edge does not exist.
// Parameters:
//   - u: source vertex.
//   - v: destination vertex.
// Returns: None
//=========================================================
void WeightedGraph::removeEdge(size_t u, size_t v)
{
    if (edgeIn(u, v))
    {
        for (int i = 0; i < adjList[u].size(); i++)
        {
            if (adjList[u][i].first == v)
            {
                adjList[u].erase(adjList[u].begin() + i);
                return;
            };
        };
    }
    throw edge_exception("edge does not exist");
}

//=========================================================
// Checks if a directed edge exists between two vertices.
// Parameters:
//   - u: source vertex.
//   - v: destination vertex.
// Returns: True if the edge exists, false otherwise.
//=========================================================
bool WeightedGraph::edgeIn(size_t u, size_t v)
{
    if (adjList.find(u) != adjList.end())
    {
        for (pair<size_t, double> value : adjList[u])
        {
            if (value.first == v)
            {
                return true;
            }
        }
    }
    return false;
}

//=========================================================
// Deletes a vertex from the graph and removes all edges associated with it.
// Parameters:
//   - u: the vertex to delete.
// Returns: None
//=========================================================
void WeightedGraph::deleteVertex(size_t u)
{
    if (adjList.find(u) == adjList.end())
    {
        throw vertex_exception("vertex does not exist");
    }

    adjList.erase(u);

    for (const pair<size_t, vector<pair<size_t, double>>> pair : adjList)
    {
        if (edgeIn(pair.first, u))
        {
            removeEdge(pair.first, u);
        }
    }
};

//=========================================================
// Adds a new vertex to the graph.
// Throws an exception if the vertex already exists.
// Parameters:
//   - u: the vertex to add.
// Returns: None
//=========================================================
void WeightedGraph::addVertex(size_t u)
{
    if (adjList.find(u) != adjList.end())
    {
        throw vertex_exception("this vertex is already existed");
    }
    adjList.insert({u, vector<pair<size_t, double>>()});
}

//=========================================================
// Performs Dijkstra's algorithm to find the shortest paths
// from a given source vertex to all other vertices in the graph.
// Throws an exception if the source vertex does not exist.
// Parameters:
//   - source: the starting vertex for Dijkstra's algorithm.
// Returns:
//   - An unordered_map where the key is the vertex, and the value
//     is a pair consisting of:
//       - The shortest distance from the source vertex.
//       - The parent vertex on the shortest path.
//=========================================================
unordered_map<size_t, pair<double, size_t>> WeightedGraph::Dijkstra(size_t source)
{
    // Check if the source vertex exists
    if (adjList.find(source) == adjList.end())
    {
        throw vertex_exception("Source vertex does not exist.");
    }
    unordered_map<size_t, pair<double, size_t>> result;

    // Set the distance from the source vertex to every vertex to INF
    // Set the parent to NIL
    for (const pair<size_t, vector<pair<size_t, double>>> pair : adjList)
    {
        result[pair.first] = {numeric_limits<double>::infinity(), -1};
    }

    // Set the distance from the source to itself to 0
    result[source].first = 0;

    Pqueue pq;

    // Insert all vertices into the priority queue with their initial distances.
    for (const pair<size_t, pair<double, size_t>> pair : result)
    {
        pq.insert(pair.first, pair.second.first);
    }

    while (!pq.isEmpty())
    {
        // Extract the vertex `u` with the smallest distance.
        size_t u = pq.extract_min();
        double distanceFromStoU = result[u].first;

        // Relax all edges (u, v) where `v` is a neighbor of `u`.
        for (const auto &neighbor : adjList[u])
        {
            size_t v = neighbor.first;
            double weight = neighbor.second;
            if (result[v].first > distanceFromStoU + weight)
            {
                result[v].first = distanceFromStoU + weight;
                result[v].second = u;
                pq.decrease_key(v, result[v].first);
            }
        }
    }

    return result;
}

double WeightedGraph::getWeight(size_t u, size_t v)
{
    for (int i = 0; i < adjList[u].size(); i++)
    {
        if (adjList[u][i].first == v)
        {
            return adjList[u][i].second;
        };
    };
    return -1;
}