#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract base class (Abstract Class, Inheritance, Access Controller)
class Device {
protected:
    string name;
    bool isOn;

public:
    Device();                          // Default Constructor
    Device(const Device& other);       // Copy Constructor
    virtual ~Device();                 // Destructor (virtual for polymorphism)

    virtual void toggle() = 0;         // Pure virtual (Abstract class + Polymorphism)
    virtual void showStatus() const = 0; // Pure virtual

    void turnOn();
    void turnOff();
    bool getIsOn() const;
    string getName() const;
    void setName(const string& n);     // Pass by reference
};