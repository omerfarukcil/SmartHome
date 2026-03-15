#pragma once
#include "Device.h"

// Struct example
struct LightConfig {
    int   minBrightness;
    int   maxBrightness;
    float defaultBrightness;
};

class Light : public Device {
private:
    float* brightness;          // Pointer (Pass by address)
    LightConfig config;

    // Friend function declaration (Friend relationship)
    friend void printLightInfo(const Light& light);

public:
    Light();
    Light(const Light& other);  // Copy constructor
    ~Light();                   // Destructor

    // Override (Polymorphism + Override)
    void toggle()      override;
    void showStatus()  const override;

    float getBrightness() const;

    // Overloaded functions (Overload)
    void setBrightness(int value);      // call by value
    void setBrightness(float value);    // call by value – different type

    void setBrightnessRef(const float& value); // call by reference
    void setBrightnessPtr(float* value);       // call by address (pointer)

    // Inline function (Inline Function)
    inline bool isMaxBrightness() const { return *brightness >= config.maxBrightness; }
};

// Friend function prototype
void printLightInfo(const Light& light);