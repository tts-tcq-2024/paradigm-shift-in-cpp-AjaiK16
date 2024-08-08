#ifndef BATTERY_MANAGEMENT_SYSTEM_H
#define BATTERY_MANAGEMENT_SYSTEM_H

#include "ParameterCheck.h"

class BatteryManagementSystem {
    ParameterCheck temperatureCheck;
    ParameterCheck socCheck;
    ParameterCheck chargeRateCheck;

public:
    BatteryManagementSystem(const ParameterCheck& tempCheck,
                            const ParameterCheck& socCheck,
                            const ParameterCheck& chargeCheck)
        : temperatureCheck(tempCheck), socCheck(socCheck), chargeRateCheck(chargeCheck) {}

    bool batteryIsOk(float temperature, float soc, float chargeRate) const {
        return temperatureCheck.check(temperature) &&
               socCheck.check(soc) &&
               chargeRateCheck.check(chargeRate);
    }
};

#endif // BATTERY_MANAGEMENT_SYSTEM_H
