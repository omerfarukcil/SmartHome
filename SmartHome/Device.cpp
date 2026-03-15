#include "Device.h"

// Default Constructor
Device::Device() : name("Unknown"), isOn(false) {}

// Copy Constructor
Device::Device(const Device& other) : name(other.name), isOn(other.isOn) {}

// Destructor
Device::~Device() {}

void Device::turnOn() { isOn = true;  cout << name << " turned ON.\n"; }
void Device::turnOff() { isOn = false; cout << name << " turned OFF.\n"; }

bool   Device::getIsOn()  const { return isOn; }
string Device::getName()  const { return name; }

// Pass by reference
void Device::setName(const string& n) { name = n; }