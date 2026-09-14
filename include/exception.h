#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class IdNotFound : public exception{
public:
    const char* what() const noexcept override;
};

class NoTaskFound : public exception{
public:
    const char* what() const noexcept override;
};

class CommandNotFound : public exception{
public:
    const char* what() const noexcept override;
};

#endif