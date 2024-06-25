#include <assert.h>
#include <iostream>
using namespace std;

// Function to check temperature range
bool isTemperatureOk(float temperature) {
    if (temperature < 0 || temperature > 45) {
        cout << "Temperature out of range!\n";
        return false;
    }
    return true;
}

// Function to check State of Charge (SOC) range
bool isSocOk(float soc) {
    if (soc < 20 || soc > 80) {
        cout << "State of Charge out of range!\n";
        return false;
    }
    return true;
}

// Function to check charge rate
bool isChargeRateOk(float chargeRate) {
    if (chargeRate > 0.8) {
        cout << "Charge Rate out of range!\n";
        return false;
    }
    return true;
}

// Function to check overall battery status
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
    // Test cases to cover all conditions
    assert(batteryIsOk(25, 70, 0.7) == true); // All within range
    assert(batteryIsOk(50, 70, 0.7) == false); // Temperature out of range
    assert(batteryIsOk(25, 85, 0.7) == false); // SOC out of range
    assert(batteryIsOk(25, 70, 0.9) == false); // Charge rate out of range
    assert(batteryIsOk(-10, 70, 0.7) == false); // Temperature below range
    assert(batteryIsOk(25, 10, 0.7) == false); // SOC below range

    cout << "All tests passed!\n";
    return 0;
}
