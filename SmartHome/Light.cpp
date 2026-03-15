#include "Light.h"

Light::Light() {
    name = "Light";
    isOn = false;
    brightness = new float(0.0f);     // dynamic allocation
    config = { 0, 100, 50.0f };
}

// Copy Constructor – deep copy for pointer member
Light::Light(const Light& other) : Device(other) {
    brightness = new float(*other.brightness);
    config = other.config;
}

// Destructor – free dynamic memory
Light::~Light() {
    delete brightness;
    brightness = nullptr;
}

// Override toggle
void Light::toggle() {
    isOn = !isOn;
    cout << name << (isOn ? " opened." : " closed.") << "\n";
}

// Override showStatus
void Light::showStatus() const {
    cout << "[Light] " << name
        << " | Status: " << (isOn ? "ON" : "OFF")
        << " | Brightness: " << *brightness << "%\n";
}

float Light::getBrightness() const { return *brightness; }

// Overload – int parameter (call by value)
void Light::setBrightness(int value) {
    if (!isOn) { cout << name << " is off! Turn it on first.\n"; return; }
    if (value < config.minBrightness || value > config.maxBrightness) {
        cout << "Invalid brightness value! (0-100)\n"; return;
    }
    *brightness = static_cast<float>(value);
    cout << name << " brightness set to " << *brightness << "%\n";
}

// Overload – float parameter (call by value)
void Light::setBrightness(float value) {
    if (!isOn) { cout << name << " is off! Turn it on first.\n"; return; }
    if (value < config.minBrightness || value > config.maxBrightness) {
        cout << "Invalid brightness value! (0-100)\n"; return;
    }
    *brightness = value;
    cout << name << " brightness set to " << *brightness << "%\n";
}

// call by reference
void Light::setBrightnessRef(const float& value) {
    setBrightness(value);
}

// call by address (pointer)
void Light::setBrightnessPtr(float* value) {
    if (value == nullptr) { cout << "Null pointer!\n"; return; }
    setBrightness(*value);
}

// Friend function – accesses private members directly
void printLightInfo(const Light& light) {
    cout << "[Friend] Light name: " << light.name
        << " | isOn: " << light.isOn
        << " | brightness ptr value: " << *light.brightness << "\n";
}