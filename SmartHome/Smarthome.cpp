#include "SmartHome.h"

SmartHome::SmartHome() : energySavingMode(false) {
    light.setName("Living Room Light");
    ac.setName("Living Room AC");
}

SmartHome::~SmartHome() {}

// ── Light ────────────────────────────────────────────────────────────────────

void SmartHome::toggleLight() {
    if (energySavingMode) {
        cout << "[Energy Saving] Cannot control light while energy saving is ON.\n";
        statusList.add("Light control blocked (energy saving mode).");
        return;
    }
    light.toggle();
    statusList.add("Light toggled -> " + string(light.getIsOn() ? "ON" : "OFF"));
}

void SmartHome::setLightBrightness(float value) {
    if (energySavingMode) {
        cout << "[Energy Saving] Cannot set brightness while energy saving is ON.\n";
        statusList.add("Brightness change blocked (energy saving mode).");
        return;
    }
    light.setBrightness(value);
    statusList.add("Light brightness changed to " + to_string(value));
}

// ── AC ───────────────────────────────────────────────────────────────────────

void SmartHome::toggleAC() {
    if (energySavingMode) {
        cout << "[Energy Saving] Cannot control AC while energy saving is ON.\n";
        statusList.add("AC control blocked (energy saving mode).");
        return;
    }
    ac.toggle();
    statusList.add("AC toggled -> " + string(ac.getIsOn() ? "ON" : "OFF"));
}

void SmartHome::setACTemperature(float value) {
    if (energySavingMode) {
        cout << "[Energy Saving] Cannot set temperature while energy saving is ON.\n";
        statusList.add("Temperature change blocked (energy saving mode).");
        return;
    }
    ac.setTemperature(value);
    statusList.add("AC temperature changed to " + to_string(value) + " C");
}

// ── Child Lock ───────────────────────────────────────────────────────────────

void SmartHome::toggleChildLock() {
    childLock.toggle();
    statusList.add(string("Child lock -> ") + (childLock.getIsLocked() ? "LOCKED" : "UNLOCKED"));
}

// ── Energy Saving ────────────────────────────────────────────────────────────

void SmartHome::enableEnergySaving() {
    energySavingMode = true;
    cout << "[Smart Home] Energy saving mode ENABLED.\n";
    statusList.add("Energy saving mode enabled.");
}

void SmartHome::disableEnergySaving() {
    energySavingMode = false;
    cout << "[Smart Home] Energy saving mode DISABLED.\n";
    statusList.add("Energy saving mode disabled.");
}

bool SmartHome::getEnergySavingMode() const { return energySavingMode; }

// ── Status ───────────────────────────────────────────────────────────────────

void SmartHome::showAllStatus() const {
    cout << "\n===== SMART HOME STATUS =====\n";
    light.showStatus();
    ac.showStatus();
    childLock.showStatus();
    cout << "Energy Saving: " << (energySavingMode ? "ON" : "OFF") << "\n";
    cout << "=============================\n\n";
}

void SmartHome::showStatusLog() const {
    cout << "\n===== STATUS LOG =====\n";
    statusList.show();
    cout << "======================\n\n";
}

// Polymorphic call via base pointer (Polymorphism)
void SmartHome::showDeviceStatus(Device* device) const {
    device->showStatus();   // virtual dispatch
}