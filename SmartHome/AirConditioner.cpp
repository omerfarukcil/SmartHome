#include "AirConditioner.h"

AirConditioner::AirConditioner() {
    name = "Air Conditioner";
    isOn = false;
    temperature = new float(0.0f);
}

AirConditioner::AirConditioner(const AirConditioner& other) : Device(other) {
    temperature = new float(*other.temperature);
}

AirConditioner::~AirConditioner() {
    delete temperature;
    temperature = nullptr;
}

void AirConditioner::toggle() {
    isOn = !isOn;
    cout << name << (isOn ? " opened." : " closed.") << "\n";
}

void AirConditioner::showStatus() const {
    cout << "[AC] " << name
        << " | Status: " << (isOn ? "ON" : "OFF")
        << " | Temperature: " << *temperature << " C\n";
}

float AirConditioner::getTemperature() const { return *temperature; }

// Overload – float (call by value)
void AirConditioner::setTemperature(float value) {
    if (!isOn) { cout << name << " is off! Turn it on first.\n"; return; }
    if (value < 16.0f || value > 30.0f) {
        cout << "Invalid temperature! (16-30 C)\n"; return;
    }
    *temperature = value;
    cout << name << " temperature set to " << *temperature << " C\n";
}

// Overload – int (call by value)
void AirConditioner::setTemperature(int value) {
    setTemperature(static_cast<float>(value));
}

// call by reference
void AirConditioner::setTemperatureRef(const float& value) {
    setTemperature(value);
}

// call by address (pointer)
void AirConditioner::setTemperaturePtr(float* value) {
    if (value == nullptr) { cout << "Null pointer!\n"; return; }
    setTemperature(*value);
}