#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

#include <exception>
#include <iostream>

using namespace std;

class edge_exception : public exception {
private:
    const char* message;
public:
    // Constructor
    edge_exception(const char* msg) {
        message = msg;
    }

    // Override the what() method
    const char* what() const noexcept {
        return message;
    }
};


class vertex_exception : public exception {
private:
    const char* message;
public:
    // Constructor
    vertex_exception(const char* msg) {
        message = msg;
    }

    // Override the what() method
    const char* what() const noexcept {
        return message;
    }
};


class ElementException : public exception {
private:
    const char* message;
public:
    // Constructor
    ElementException(const char* msg) {
        message = msg;
    }

    // Override the what() method
    const char* what() const noexcept {
        return message;
    }
};


class KeyException : public exception {
private:
    const char* message;
public:
    // Constructor
    KeyException(const char* msg) {
        message = msg;
    }

    // Override the what() method
    const char* what() const noexcept {
        return message;
    }
};


#endif