#include <cassert>
#include "BatteryManagementSystem.h"
#include "MessageHandler.h"

void runTests() {
    MessageHandler msgHandler("DE");

    RangeChecker temperatureRange(0, 45, 0.05 * 45);
    ParameterCheck temperatureCheck(temperatureRange,
                                    "Temperature out of range!", "Temperatur außerhalb des Bereichs!",
                                    "Temperature approaching upper limit", "Temperatur nähert sich der oberen Grenze",
                                    msgHandler);

    RangeChecker socRange(20, 80, 0.05 * 80);
    ParameterCheck socCheck(socRange,
                            "State of Charge out of range!", "Ladezustand außerhalb des Bereichs!",
                            "SOC approaching discharge", "SOC nähert sich der Entladung",
                            msgHandler);

    RangeChecker chargeRateRange(0, 0.8, 0.05 * 0.8);
    ParameterCheck chargeRateCheck(chargeRateRange,
                                   "Charge Rate out of range!", "Laderate außerhalb des Bereichs!",
                                   "Charge rate approaching upper limit", "Laderate nähert sich der oberen Grenze",
                                   msgHandler);

    BatteryManagementSystem bms(temperatureCheck, socCheck, chargeRateCheck);

    // Test cases to cover all conditions
    assert(bms.batteryIsOk(25, 70, 0.7) == true);
    assert(bms.batteryIsOk(50, 70, 0.7) == false);
    assert(bms.batteryIsOk(25, 85, 0.7) == false);
    assert(bms.batteryIsOk(25, 70, 0.9) == false);
    assert(bms.batteryIsOk(-10, 70, 0.7) == false);
    assert(bms.batteryIsOk(25, 10, 0.7) == false);

    std::cout << "All tests passed!\n";
}

int main() {
    runTests();
    return 0;
}
