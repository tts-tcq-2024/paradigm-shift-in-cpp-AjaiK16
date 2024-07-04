#include <assert.h>
#include <iostream>
using namespace std;

bool isWithinRange(float value, float min, float max) {
    return value >= min && value <= max;
}

bool isBelowMax(float value, float max) {
    return value <= max;
}

bool checkRangeAndReport(float value, float min, float max, const char* errorMessage) {
    if (!isWithinRange(value, min, max)) {
        cout << errorMessage << endl;
        return false;
    }
    return true;
}

bool checkMaxAndReport(float value, float max, const char* errorMessage) {
    if (!isBelowMax(value, max)) {
        cout << errorMessage << endl;
        return false;
    }
    return true;
}

bool isTemperatureOk(float temperature) {
    return checkRangeAndReport(temperature, 0, 45, "Temperature out of range!");
}

bool isSocOk(float soc) {
    return checkRangeAndReport(soc, 20, 80, "State of Charge out of range!");
}

bool isChargeRateOk(float chargeRate) {
    return checkMaxAndReport(chargeRate, 0.8, "Charge Rate out of range!");
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true); 
    assert(batteryIsOk(50, 70, 0.7) == false);
    assert(batteryIsOk(25, 85, 0.7) == false);
    assert(batteryIsOk(25, 70, 0.9) == false);
    assert(batteryIsOk(-10, 70, 0.7) == false);
    assert(batteryIsOk(25, 10, 0.7) == false); 
    return 0;
}

