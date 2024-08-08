#include <iostream>
#include "BatteryManagementSystem.h"
#include "MessageHandler.h"

int main() {
    MessageHandler msgHandler("EN");

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

    std::cout << (bms.batteryIsOk(25, 70, 0.7) ? "Battery is OK" : "Battery is NOT OK") << std::endl;

    return 0;
}
