#include <iostream>
#include <limits>
#include "SmartHome.h"

using namespace std;

// ── Template Function (Template) ─────────────────────────────────────────────
// Works for both int and float brightness/temperature values
template <typename T>
T clampValue(T value, T minVal, T maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

// ── Helper to clear invalid input ────────────────────────────────────────────
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ── Menu ─────────────────────────────────────────────────────────────────────
void showMenu(const SmartHome& home) {
    cout << "\n========= SMART HOME MENU =========\n";
    cout << " 1. Toggle Light\n";
    cout << " 2. Set Light Brightness\n";
    cout << " 3. Toggle Air Conditioner\n";
    cout << " 4. Set AC Temperature\n";
    cout << " 5. Toggle Child Lock\n";
    cout << " 6. Enable Energy Saving Mode\n";
    cout << " 7. Disable Energy Saving Mode\n";
    cout << " 8. Show All Device Status\n";
    cout << " 9. Show Status Log\n";
    cout << " 10. Show Friend Function Demo\n";
    cout << " 11. Show Polymorphism Demo\n";
    cout << " 0. Exit\n";
    cout << "===================================\n";
    cout << "Choice: ";
}

int main() {
    SmartHome home;

    // ── Demonstrate Copy Constructor ──────────────────────────────────────────
    Light originalLight;
    originalLight.setName("Original Light");
    originalLight.turnOn();
    originalLight.setBrightness(75);

    Light copiedLight(originalLight);      // Copy constructor
    copiedLight.setName("Copied Light");
    cout << "[Copy Constructor Demo]\n";
    originalLight.showStatus();
    copiedLight.showStatus();
    cout << "\n";

    // ── Demonstrate Pass by Address ───────────────────────────────────────────
    float brightness = 60.0f;
    originalLight.setBrightnessPtr(&brightness);   // pass by address (pointer)

    // ── Demonstrate Template Function ─────────────────────────────────────────
    int   clamped_i = clampValue(150, 0, 100);     // T = int
    float clamped_f = clampValue(5.0f, 16.0f, 30.0f); // T = float
    cout << "[Template Demo] clampValue(150, 0, 100) = " << clamped_i << "\n";
    cout << "[Template Demo] clampValue(5.0, 16, 30) = " << clamped_f << "\n\n";

    // ── Main Menu Loop ────────────────────────────────────────────────────────
    int choice = -1;
    while (choice != 0) {
        showMenu(home);
        cin >> choice;
        if (cin.fail()) { clearInput(); choice = -1; continue; }

        switch (choice) {
        case 1:
            home.toggleLight();
            break;

        case 2: {
            float val;
            cout << "Enter brightness (0-100): ";
            cin >> val;
            if (cin.fail()) { clearInput(); break; }
            val = clampValue(val, 0.0f, 100.0f);  // template usage
            home.setLightBrightness(val);
            break;
        }

        case 3:
            home.toggleAC();
            break;

        case 4: {
            float val;
            cout << "Enter temperature (16-30): ";
            cin >> val;
            if (cin.fail()) { clearInput(); break; }
            val = clampValue(val, 16.0f, 30.0f);  // template usage
            home.setACTemperature(val);
            break;
        }

        case 5:
            home.toggleChildLock();
            break;

        case 6:
            home.enableEnergySaving();
            break;

        case 7:
            home.disableEnergySaving();
            break;

        case 8:
            home.showAllStatus();
            break;

        case 9:
            home.showStatusLog();
            break;

        case 10: {
            // Friend function demo
            Light demoLight;
            demoLight.setName("Demo Light");
            demoLight.turnOn();
            demoLight.setBrightness(42);
            cout << "\n[Friend Function Demo]\n";
            printLightInfo(demoLight);   // friend function accesses private members
            break;
        }

        case 11: {
            // Polymorphism demo – base class pointer array
            cout << "\n[Polymorphism Demo]\n";
            Light      polyLight;
            AirConditioner polyAC;
            ChildLock  polyLock;

            polyLight.setName("Poly Light");
            polyAC.setName("Poly AC");
            polyLock.setName("Poly Lock");

            Device* devices[] = { &polyLight, &polyAC, &polyLock };  // Device* (base ptr)
            for (Device* d : devices)
                d->showStatus();   // virtual dispatch (Polymorphism)
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }

    return 0;
}