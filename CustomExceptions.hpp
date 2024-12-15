#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

#include <stdexcept>
#include <string>


class KeyException : public std::runtime_error {
public:
    explicit KeyException(const std::string& message)
        : std::runtime_error("KeyException: " + message) {}
};

class ElementException : public std::runtime_error {
public:
    explicit ElementException(const std::string& message)
        : std::runtime_error("ElementException: " + message) {}
};



#endif