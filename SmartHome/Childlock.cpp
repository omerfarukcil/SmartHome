#include "ChildLock.h"

ChildLock::ChildLock() : isLocked(false) {
    name = "Child Lock";
    isOn = true;
}

ChildLock::ChildLock(const ChildLock& other) : Device(other) {
    isLocked = other.isLocked;
}

ChildLock::~ChildLock() {}

void ChildLock::toggle() {
    isLocked = !isLocked;
    cout << name << (isLocked ? " LOCKED." : " UNLOCKED.") << "\n";
}

void ChildLock::showStatus() const {
    cout << "[ChildLock] " << name
        << " | Status: " << (isLocked ? "LOCKED" : "UNLOCKED") << "\n";
}

void ChildLock::lock() { isLocked = true;  cout << name << " LOCKED.\n"; }
void ChildLock::unlock() { isLocked = false; cout << name << " UNLOCKED.\n"; }
bool ChildLock::getIsLocked() const { return isLocked; }