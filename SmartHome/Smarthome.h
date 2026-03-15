#pragma once
#include "Light.h"
#include "AirConditioner.h"
#include "ChildLock.h"
#include "StatusList.h"

class SmartHome {
private:
    Light          light;
    AirConditioner ac;
    ChildLock      childLock;
    StatusList     statusList;
    bool           energySavingMode;

public:
    SmartHome();
    ~SmartHome();

    // Device control
    void toggleLight();
    void toggleAC();
    void toggleChildLock();

    void setLightBrightness(float value);
    void setACTemperature(float value);

    void enableEnergySaving();
    void disableEnergySaving();
    bool getEnergySavingMode() const;

    void showAllStatus() const;
    void showStatusLog()  const;

    // Polymorphic display (uses Device* base pointer)
    void showDeviceStatus(Device* device) const;
};