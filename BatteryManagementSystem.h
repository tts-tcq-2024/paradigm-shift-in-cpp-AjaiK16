
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
                            const ParameterCheck& chargeCheck);

    bool batteryIsOk(float temperature, float soc, float chargeRate) const;
};

#endif // BATTERY_MANAGEMENT_SYSTEM_H
