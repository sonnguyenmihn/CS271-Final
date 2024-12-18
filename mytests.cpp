//=========================================================
// mytests.cpp
// Son, Damian, Hoa
// Dec, 2024
// This is the test file for the WeightedGraph class and min Pqueue class
//=========================================================
#include "Pqueue.hpp"
#include "WeightedGraph.hpp"
#include "CustomExceptions.hpp"
#include <iostream>
using namespace std;

int passedTests = 0; // Counter for passed tests
int failedTests = 0; // Counter for failed tests

// Helper function to record test results
void recordTestResult(bool passed) {
    if (passed) {
        ++passedTests;
    } else {
        ++failedTests;
    }
}

// Test 1: Insert elements and view the minimum
void testInsertAndViewMin() {
    cout << "Test: Insert and View Minimum\n";
    try {
        Pqueue pq;
        pq.insert(10, 1);
        pq.insert(20, 2);
        pq.insert(5, 0.5);
        if (pq.viewMin() == 5) {
            cout << "-> Passed: Minimum is correct after insertion.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Incorrect minimum after insertion.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during insert or viewMin.\n";
        recordTestResult(false);
    }
}

// Test 2: Extract minimum element
void testExtractMin() {
    cout << "Test: Extract Minimum\n";
    try {
        Pqueue pq;
        pq.insert(10, 1);
        pq.insert(20, 2);
        pq.insert(5, 0.5);
        double min = pq.extract_min();
        if (min == 5 && pq.viewMin() == 10) {
            cout << "-> Passed: Extracted minimum and heap updated correctly.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Incorrect behavior of extract_min.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during extract_min.\n";
        recordTestResult(false);
    }
}

// Test 3: Decrease key of an element
void testDecreaseKey() {
    cout << "Test: Decrease Key\n";
    try {
        Pqueue pq;
        pq.insert(10, 5);
        pq.insert(20, 10);
        pq.decrease_key(20, 3);
        if (pq.viewMin() == 20) {
            cout << "-> Passed: Key decreased and heap updated correctly.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Heap did not update after decrease_key.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during decrease_key.\n";
        recordTestResult(false);
    }
}

// Test 4: Attempt to extract from an empty queue
void testExtractMinEmpty() {
    cout << "Test: Extract from Empty Queue\n";
    try {
        Pqueue pq;
        pq.extract_min(); // Should throw exception
        cout << "-> Failed: No exception thrown for empty extract_min.\n";
        recordTestResult(false);
    } catch (const ElementException&) {
        cout << "-> Passed: Correct exception thrown for empty extract_min.\n";
        recordTestResult(true);
    } catch (...) {
        cout << "-> Failed: Incorrect exception type thrown.\n";
        recordTestResult(false);
    }
}

// Test 5: Decrease key with invalid value
void testDecreaseKeyInvalidValue() {
    cout << "Test: Decrease Key with Invalid Value\n";
    try {
        Pqueue pq;
        pq.insert(10, 5);
        pq.decrease_key(15, 3); // 15 does not exist
        cout << "-> Failed: No exception thrown for non-existing value.\n";
        recordTestResult(false);
    } catch (const ElementException&) {
        cout << "-> Passed: Correct exception thrown for invalid value in decrease_key.\n";
        recordTestResult(true);
    } catch (...) {
        cout << "-> Failed: Incorrect exception type thrown.\n";
        recordTestResult(false);
    }
}

// Test 6: Check if the queue is empty
void testIsEmpty() {
    cout << "Test: Check if Queue is Empty\n";
    try {
        Pqueue pq;
        if (pq.isEmpty()) {
            pq.insert(10, 1);
            if (!pq.isEmpty()) {
                cout << "-> Passed: isEmpty function works correctly.\n";
                recordTestResult(true);
            } else {
                throw runtime_error("isEmpty returned true after insertion.");
            }
        } else {
            throw runtime_error("isEmpty returned false for an empty queue.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during isEmpty.\n";
        recordTestResult(false);
    }
}

// Test 7: Insert multiple elements with the same value but different keys
void testInsertDuplicateValues() {
    cout << "Test: Insert Duplicate Values with Different Keys\n";
    try {
        Pqueue pq;
        pq.insert(10, 5);
        pq.insert(10, 3); // Same value, different priority
        if (pq.viewMin() == 10) {
            cout << "-> Passed: Duplicate values handled correctly.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Incorrect behavior for duplicate values.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown for duplicate values.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test Default Constructor
// Purpose:
//  - Ensure the default constructor initializes an empty graph.
//=========================================================
void testDefaultConstructor() {
    cout << "Test: Default Constructor\n";
    try {
        WeightedGraph graph;
        recordTestResult(true);
    } catch (...) {
        cout << "-> Failed: Exception thrown during default constructor test.\n";
        recordTestResult(false);
    }
}

//=========================================================
// Test Copy Constructor
// Purpose:
//  - Ensure the copy constructor creates an exact copy of the graph.
//=========================================================
void testCopyConstructor() {
    cout << "Test: Copy Constructor\n";
    try {
        WeightedGraph graph1;
        graph1.addVertex(1);
        graph1.addVertex(2);
        graph1.addEdge(1, 2, 5.0);

        WeightedGraph graph2(graph1); // Use copy constructor

        if (graph2.edgeIn(1, 2)) {
            cout << "-> Passed: Copy constructor creates a correct copy.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Copied graph does not contain expected edge.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during copy constructor test.\n";
        recordTestResult(false);
    }
}

//=========================================================
// Test Assignment Operator
// Purpose:
//  - Ensure the assignment operator correctly copies the graph data.
//=========================================================
void testAssignmentOperator() {
    cout << "Test: Assignment Operator\n";
    try {
        WeightedGraph graph1;
        graph1.addVertex(1);
        graph1.addVertex(2);
        graph1.addEdge(1, 2, 5.0);

        WeightedGraph graph2;
        graph2 = graph1; // Use assignment operator

        if (graph2.edgeIn(1, 2)) {
            cout << "-> Passed: Assignment operator copies graph correctly.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Assigned graph does not contain expected edge.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during assignment operator test.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test addVertex
// Purpose:
//  - Ensure vertices are added correctly to the graph.
//=========================================================
void testAddVertex() {
    cout << "Test: Add Vertex\n";
    try {
        WeightedGraph graph;
        graph.addVertex(1);
        graph.addVertex(2);
        graph.addVertex(3);
        cout << "-> Passed: Vertices added without exceptions.\n";
        recordTestResult(true);
    } catch (...) {
        cout << "-> Failed: Exception thrown during addVertex.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test duplicate addVertex
// Purpose:
//  - Ensure duplicate vertices throw exceptions.
//=========================================================
void testAddVertexDuplicate() {
    cout << "Test: Add Duplicate Vertex\n";
    try {
        WeightedGraph graph;
        graph.addVertex(1);
        graph.addVertex(1); // Should throw an exception
        cout << "-> Failed: No exception thrown for duplicate vertex.\n";
        recordTestResult(false);
    } catch (const vertex_exception &) {
        cout << "-> Passed: Correct exception thrown for duplicate vertex.\n";
        recordTestResult(true);
    } catch (...) {
        cout << "-> Failed: Incorrect exception type thrown for duplicate vertex.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test addEdge
// Purpose:
//  - Ensure edges are added correctly between vertices.
//=========================================================
void testAddEdge() {
    cout << "Test: Add Edge\n";
    try {
        WeightedGraph graph;
        graph.addVertex(1);
        graph.addVertex(2);
        graph.addEdge(1, 2, 5.0);
        if (graph.edgeIn(1, 2)) {
            cout << "-> Passed: Edge added successfully.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Edge not found after addition.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during addEdge.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test addEdge with missing vertices
// Purpose:
//  - Ensure adding edges fails when vertices are missing.
//=========================================================
void testAddEdgeMissingVertices() {
    cout << "Test: Add Edge with Missing Vertices\n";
    try {
        WeightedGraph graph;
        graph.addVertex(1);
        graph.addEdge(1, 3, 5.0); // Vertex 3 does not exist
        cout << "-> Failed: No exception thrown for missing vertices.\n";
        recordTestResult(false);
    } catch (const vertex_exception &) {
        cout << "-> Passed: Correct exception thrown for missing vertices.\n";
        recordTestResult(true);
    } catch (...) {
        cout << "-> Failed: Incorrect exception type thrown for missing vertices.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test removeEdge
// Purpose:
//  - Ensure edges are removed correctly between vertices.
//=========================================================
void testRemoveEdge() {
    cout << "Test: Remove Edge\n";
    try {
        WeightedGraph graph;
        graph.addVertex(1);
        graph.addVertex(2);
        graph.addEdge(1, 2, 5.0);
        graph.removeEdge(1, 2);
        if (!graph.edgeIn(1, 2)) {
            cout << "-> Passed: Edge removed successfully.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Edge still exists after removal.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during removeEdge.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test removeEdge with non-existent edge
// Purpose:
//  - Ensure removing a non-existent edge throws an exception.
//=========================================================
void testRemoveEdgeNonExistent() {
    cout << "Test: Remove Non-Existent Edge\n";
    try {
        WeightedGraph graph;
        graph.addVertex(1);
        graph.addVertex(2);
        graph.removeEdge(1, 2); // Edge does not exist
        cout << "-> Failed: No exception thrown for non-existent edge.\n";
        recordTestResult(false);
    } catch (const edge_exception &) {
        cout << "-> Passed: Correct exception thrown for non-existent edge.\n";
        recordTestResult(true);
    } catch (...) {
        cout << "-> Failed: Incorrect exception type thrown for non-existent edge.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test Dijkstra's algorithm
// Purpose:
//  - Ensure shortest paths are computed correctly.
//=========================================================
void testDijkstra() {
    cout << "Test: Dijkstra's Algorithm\n";
    try {
        WeightedGraph graph;
        graph.addVertex(1);
        graph.addVertex(2);
        graph.addVertex(3);
        graph.addEdge(1, 2, 1.0);
        graph.addEdge(2, 3, 2.0);
        graph.addEdge(1, 3, 4.0);

        auto result = graph.Dijkstra(1);
        if (result[3].first == 3.0 && result[3].second == 2) {
            cout << "-> Passed: Dijkstra computed correct shortest path.\n";
            recordTestResult(true);
        } else {
            throw runtime_error("Incorrect result for Dijkstra.");
        }
    } catch (...) {
        cout << "-> Failed: Exception thrown during Dijkstra.\n";
        recordTestResult(false);
    }
}


//=========================================================
// Test Dijkstra with missing source vertex
// Purpose:
//  - Ensure Dijkstra fails when the source vertex is missing.
//=========================================================
void testDijkstraMissingSource() {
    cout << "Test: Dijkstra with Missing Source Vertex\n";
    try {
        WeightedGraph graph;
        graph.addVertex(1);
        graph.Dijkstra(2); // Vertex 2 does not exist
        cout << "-> Failed: No exception thrown for missing source vertex.\n";
        recordTestResult(false);
    } catch (const vertex_exception &) {
        cout << "-> Passed: Correct exception thrown for missing source vertex.\n";
        recordTestResult(true);
    } catch (...) {
        cout << "-> Failed: Incorrect exception type thrown for missing source vertex.\n";
        recordTestResult(false);
    }
}


// Main driver to run all tests
int main() {

    // tests for Pqueue class
    testInsertAndViewMin();
    testExtractMin();
    testDecreaseKey();
    testExtractMinEmpty();
    testDecreaseKeyInvalidValue();
    testIsEmpty();
    testInsertDuplicateValues();

    // tests for Weighted Graph class
    testDefaultConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testAddVertex();
    testAddVertexDuplicate();
    testAddEdge();
    testAddEdgeMissingVertices();
    testRemoveEdge();
    testRemoveEdgeNonExistent();
    testDijkstra();
    testDijkstraMissingSource();

    cout << "\nSummary:\n";
    cout << "Tests Passed: " << passedTests << "\n";
    cout << "Tests Failed: " << failedTests << "\n";

    return 0;
}
