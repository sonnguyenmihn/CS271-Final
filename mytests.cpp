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

// Main driver to run all tests
int main() {
    testInsertAndViewMin();
    testExtractMin();
    testDecreaseKey();
    testExtractMinEmpty();
    testDecreaseKeyInvalidValue();
    testIsEmpty();
    testInsertDuplicateValues();

    cout << "\nSummary:\n";
    cout << "Tests Passed: " << passedTests << "\n";
    cout << "Tests Failed: " << failedTests << "\n";

    return 0;
}
