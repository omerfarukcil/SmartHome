#pragma once
#include "Device.h"

class ChildLock : public Device {
private:
    bool isLocked;

public:
    ChildLock();
    ChildLock(const ChildLock& other);
    ~ChildLock();

    void toggle()     override;
    void showStatus() const override;

    void lock();
    void unlock();
    bool getIsLocked() const;
};