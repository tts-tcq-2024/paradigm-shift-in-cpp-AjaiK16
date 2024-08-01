#include <cassert>
#include "battmgsys.h"

void testBatteryManagementSystem() {
    BatteryManagementSystem bms;

    bms.setLanguage(Language::ENGLISH);

    assert(bms.batteryIsOk(25, 70, 0.7) == true);
    assert(bms.batteryIsOk(50, 70, 0.7) == false);
    assert(bms.batteryIsOk(25, 85, 0.7) == false);
    assert(bms.batteryIsOk(25, 70, 0.9) == false);
    assert(bms.batteryIsOk(-10, 70, 0.7) == false);
    assert(bms.batteryIsOk(25, 10, 0.7) == false);

    bms.setLanguage(Language::GERMAN);

    assert(bms.batteryIsOk(25, 70, 0.7) == true);
    assert(bms.batteryIsOk(50, 70, 0.7) == false);
    assert(bms.batteryIsOk(25, 85, 0.7) == false);
    assert(bms.batteryIsOk(25, 70, 0.9) == false);
    assert(bms.batteryIsOk(-10, 70, 0.7) == false);
    assert(bms.batteryIsOk(25, 10, 0.7) == false);
}

int main() {
    testBatteryManagementSystem();
    return 0;
}
