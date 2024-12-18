//=========================================================
// CLI.hpp
// Son, Damian, Hoa
// Dec, 2024
// This is the Command Line interface program for finding the shortest path from a source
//=========================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include "WeightedGraph.hpp"

using namespace std;

class GraphCLI
{
public:
    // This function ask for a input file, read the graph in the file to the `graph` variable
    bool getGraph()
    {
        // Clear the current graph
        coordinatesToID.clear();
        IDToCoordinates.clear();
        edgeNames.clear();
        graph = WeightedGraph();

        // File input
        string filename;
        ifstream file;
        bool fileOpened = false;

        // Loop until a valid file is opened
        while (!fileOpened)
        {
            cout << "Enter the file name to load the graph: ";
            cin >> filename;

            if (filename == "q")
            {
                return false;
            }

            file.open(filename);

            if (file.is_open())
            {
                cout << "File opened successfully!" << endl;
                fileOpened = true; // Exit the loop if the file is successfully opened
            }
            else
            {
                cout << "Could not open the file. Please enter another file." << endl;
            }
        }

        // Load the input graph to `graph` variable
        int numVertices, numEdges;
        file >> numVertices >> numEdges;

        // Add vertices to graph
        for (int i = 0; i < numVertices; ++i)
        {
            size_t id;
            double x, y;
            file >> id >> x >> y;

            string combinedCoordinate = to_string(x) + ", " + to_string(y);
            coordinatesToID[combinedCoordinate] = id;
            IDToCoordinates[id] = combinedCoordinate;
            graph.addVertex(id);
            // cout << id <<" " << x << " " << y << endl;
        }

        // Add edges to graph
        for (int i = 0; i < numEdges; ++i)
        {
            size_t u, v;
            double w;
            string streetName;

            file >> u >> v >> w;

            getline(file, streetName);
            if (streetName.size() > 1)
            {
                string combinedID = to_string(u) + ", " + to_string(v);
                edgeNames[combinedID] = streetName;
            }
            // cout << u << " " << v << " " << w << streetName << endl;
            graph.addEdge(u, v, w);
        }

        return true;
    }

    void getPath()
    {
        // Variables to store user input for start and end coordinates
        double startX, startY, endX, endY;
        string combinedStartCoordinate, combinedEndCoordinate;
        while (true)
        {
            // Booleans to track if valid start and end coordinates have been entered
            bool found1 = false;
            bool found2 = false;

            // Get the start coordinate
            while (!found1)
            {
                cout << "Enter a start coordinate (x y): ";
                string tmp;
                cin >> tmp;

                // If the user enters 'q', exit the function
                if (tmp == "q")
                {
                    return;
                }
                startX = stod(tmp); // convert string to double

                cin >> startY;

                // Combine the x and y coordinates into a single key for lookup
                combinedStartCoordinate = to_string(startX) + ", " + to_string(startY);

                // Check if the vertex exists in the graph
                if (coordinatesToID.find(combinedStartCoordinate) != coordinatesToID.end())
                {
                    found1 = true;
                }
                else
                {
                    cout << "Invalid: There is no coordinates " << startX << ", " << startY << " in the map" << endl;
                }
            }

            // Get the destination coordinate
            while (!found2 && found1)
            {
                cout << "Enter an end coordinate (x y): ";
                string tmp;
                cin >> tmp;
                if (tmp == "q")
                {
                    return;
                }
                endX = stod(tmp);
                cin >> endY;
                combinedEndCoordinate = to_string(endX) + ", " + to_string(endY);

                // Check if the vertex exists in the graph
                if (coordinatesToID.find(combinedEndCoordinate) != coordinatesToID.end())
                {
                    found2 = true;
                }
                else
                {
                    cout << "Invalid: There is no coordinates " << endX << ", " << endY << " in the map" << endl;
                }
            }

            // Perform Dijkstra's algorithm to find the shortest path from start to end
            size_t startVertex = coordinatesToID[combinedStartCoordinate];
            size_t endVertex = coordinatesToID[combinedEndCoordinate];
            unordered_map<size_t, pair<double, size_t>> result = graph.Dijkstra(startVertex); // result from dijkstra

            if (result[endVertex].first == numeric_limits<double>::infinity())
            {
                cout << "There is no path from " << startVertex << " to " << endVertex << endl;
            }
            else
            {
                cout << "The shortest path from (" << combinedStartCoordinate << ") to (" << combinedEndCoordinate << ") is: ";
                cout << "(" << combinedStartCoordinate << ")";
                double weight = 0;
                printPath(result, startVertex, endVertex, weight);
                cout << " and its weight is: " << weight << endl;
            }
        }
    }

    void printPath(unordered_map<size_t, pair<double, size_t>> &result, size_t startVertex, size_t endVertex, double &weight)
    {
        if (startVertex == endVertex)
        {
            return;
        }
        // get the weight of an edge from endVertex's parent to endVertex
        weight += graph.getWeight(result[endVertex].second, endVertex);

        // Recursively call printPath
        printPath(result, startVertex, result[endVertex].second, weight);

        // Print an edge at each recursion
        cout << " ---";
        string edge = to_string(result[endVertex].second) + ", " + to_string(endVertex);
        if (edgeNames.find(edge) != edgeNames.end())
        {
            cout << edgeNames[edge];
        }
        cout << "---> ";
        cout << "(" << IDToCoordinates[endVertex] << ")";
    }

private:
    WeightedGraph graph;
    unordered_map<string, size_t> coordinatesToID;
    unordered_map<size_t, string> IDToCoordinates;
    unordered_map<string, string> edgeNames;
};

int main()
{
    GraphCLI cli;
    cout << "Welcome to the CLI graph program! You may enter the letter 'q' at any time to exit.\n";
    if (cli.getGraph())
    {
        cli.getPath();
    }

    cout << "Exiting... Thank you for using the graph CLI program!" << endl;
    return 0;
}
