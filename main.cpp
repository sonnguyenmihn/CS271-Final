#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "WeightedGraph.hpp"
#include "Pqueue.hpp"

using namespace std;

void loadGraph(WeightedGraph &graph, const string &filename, unordered_map<long long, pair<double, double>> &nodes) {
   ifstream file(filename);
   if (!file.is_open()) {
       throw runtime_error("Could not open the file.");
   }

   int n, m;
   file >> n >> m;

    for (int i = 0; i < n; ++i) {
        long long id;
        double x, y;
        file >> id >> x >> y;
        nodes[id] = {x, y};
    }
  
    for (int i = 0; i < m; ++i) {
        long long u, v;     
        double w;
        string streetName;


        file >> u >> v >> w;
        
        getline(file, streetName); 


        if (streetName.empty()) {
            streetName = "Unknown"; 
    }
    //cout << u << ", " << v << ", " << w << streetName << endl;
    graph.addEdge(u, v, w);  
    }

}

// int findNodeByCoordinates(double startX, double startY, const unordered_map<long long, pair<double, double>>& nodes) {


//     for (const auto& pair : nodes) {
//         double nodeX = pair.second.first;
//         double nodeY = pair.second.second;
//     }


//     return -1;
// }

int main() {
   WeightedGraph graph;
   unordered_map<long long, pair<double, double>> nodes;

   cout << "Welcome to the CLI graph program! You may enter the letter 'q' at any time to exit.\n";

   string filename;
   cout << "Enter the file name to load the graph: ";
   cin >> filename;

   try {
       loadGraph(graph, filename, nodes);
   } catch (const exception& e) {
       cerr << e.what() << endl;
       return 1;
   }

   while (true) {
       double startX, startY, endX, endY;

       cout << "Enter the start coordinate (x y): ";
       cin >> startX >> startY;

       if (cin.fail()) {
           string quit;
           cin >> quit;
           if (quit == "q") break;
           cerr << "Invalid input! Please enter valid coordinates." << endl;
           cin.clear();
           continue;
       }

       cout << "Enter the end coordinate (x y): ";
       cin >> endX >> endY;

       if (cin.fail()) {
           string quit;
           cin >> quit;
           if (quit == "q") break;
           cerr << "Invalid input! Please enter valid coordinates." << endl;
           cin.clear();
           continue;
       }

       int startVertex = findNodeByCoordinates(startX, startY, nodes);
       int endVertex = findNodeByCoordinates(endX, endY, nodes);
       cout << startVertex;

       unordered_map<double, pair<double, double>> shortestDistance = graph.Dijkstra(startVertex);

   }

   cout << "Exiting... Thank you for using the graph CLI program!" << endl;
   return 0;
}
