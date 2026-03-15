#pragma once
#include "Device.h"

class AirConditioner : public Device {
private:
    float* temperature;    // Pointer

public:
    AirConditioner();
    AirConditioner(const AirConditioner& other);  // Copy constructor
    ~AirConditioner();                            // Destructor

    void toggle()     override;
    void showStatus() const override;

    float getTemperature() const;

    // Overloaded setTemperature (Overload)
    void setTemperature(float value);   // call by value (float)
    void setTemperature(int value);     // call by value (int)

    void setTemperatureRef(const float& value);  // call by reference
    void setTemperaturePtr(float* value);        // call by address
};