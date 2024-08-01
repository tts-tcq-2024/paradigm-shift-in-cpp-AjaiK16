#include "battmgsys.h"
#include <iostream>
#include <map>

BatteryManagementSystem::BatteryManagementSystem(Language lang) : currentLanguage(lang) {
    messages = {
        { Language::ENGLISH, {
            { "TEMP_OK", "Temperature is OK." },
            { "TEMP_WARNING_LOW", "Approaching low temperature." },
            { "TEMP_WARNING_HIGH", "Approaching high temperature." },
            { "TEMP_BREACH_LOW", "Temperature too low!" },
            { "TEMP_BREACH_HIGH", "Temperature too high!" },
            { "SOC_OK", "State of Charge is OK." },
            { "SOC_WARNING_LOW", "Approaching low State of Charge." },
            { "SOC_WARNING_HIGH", "Approaching high State of Charge." },
            { "SOC_BREACH_LOW", "State of Charge too low!" },
            { "SOC_BREACH_HIGH", "State of Charge too high!" },
            { "CHARGE_RATE_OK", "Charge Rate is OK." },
            { "CHARGE_RATE_WARNING", "Approaching high Charge Rate." },
            { "CHARGE_RATE_BREACH", "Charge Rate too high!" }
        }},
        { Language::GERMAN, {
            { "TEMP_OK", "Temperatur ist OK." },
            { "TEMP_WARNING_LOW", "Nähern sich niedriger Temperatur." },
            { "TEMP_WARNING_HIGH", "Nähern sich hoher Temperatur." },
            { "TEMP_BREACH_LOW", "Temperatur zu niedrig!" },
            { "TEMP_BREACH_HIGH", "Temperatur zu hoch!" },
            { "SOC_OK", "Ladezustand ist OK." },
            { "SOC_WARNING_LOW", "Nähern sich niedrigem Ladezustand." },
            { "SOC_WARNING_HIGH", "Nähern sich hohem Ladezustand." },
            { "SOC_BREACH_LOW", "Ladezustand zu niedrig!" },
            { "SOC_BREACH_HIGH", "Ladezustand zu hoch!" },
            { "CHARGE_RATE_OK", "Ladegeschwindigkeit ist OK." },
            { "CHARGE_RATE_WARNING", "Nähern sich hoher Ladegeschwindigkeit." },
            { "CHARGE_RATE_BREACH", "Ladegeschwindigkeit zu hoch!" }
        }}
    };
}

void BatteryManagementSystem::setLanguage(Language lang) {
    currentLanguage = lang;
}

bool BatteryManagementSystem::isInRange(float value, float min, float max) const {
    return value >= min && value <= max;
}

bool BatteryManagementSystem::isBelowThreshold(float value, float max) const {
    return value <= max;
}

bool BatteryManagementSystem::checkRangeAndReport(float value, float min, float max, const std::string& warningMsg, const std::string& breachMsg) const {
    if (value < min) {
        std::cout << translateMessage(breachMsg) << std::endl;
        return false;
    }
    if (value < min + 0.05 * (max - min)) {
        std::cout << translateMessage(warningMsg + "_LOW") << std::endl;
    }
    if (value > max - 0.05 * (max - min)) {
        std::cout << translateMessage(warningMsg + "_HIGH") << std::endl;
    }
    if (value > max) {
        std::cout << translateMessage(breachMsg) << std::endl;
        return false;
    }
    return true;
}

bool BatteryManagementSystem::checkMaxAndReport(float value, float max, const std::string& warningMsg, const std::string& breachMsg) const {
    if (value > max) {
        std::cout << translateMessage(breachMsg) << std::endl;
        return false;
    }
    if (value > max - 0.05 * max) {
        std::cout << translateMessage(warningMsg) << std::endl;
    }
    return true;
}

std::string BatteryManagementSystem::translateMessage(const std::string& key) const {
    return messages.at(currentLanguage).at(key);
}

bool BatteryManagementSystem::isTemperatureOk(float temperature) const {
    return checkRangeAndReport(temperature, 0, 45, "TEMP_WARNING", "TEMP_BREACH");
}

bool BatteryManagementSystem::isSocOk(float soc) const {
    return checkRangeAndReport(soc, 20, 80, "SOC_WARNING", "SOC_BREACH");
}

bool BatteryManagementSystem::isChargeRateOk(float chargeRate) const {
    return checkMaxAndReport(chargeRate, 0.8, "CHARGE_RATE_WARNING", "CHARGE_RATE_BREACH");
}

bool BatteryManagementSystem::batteryIsOk(float temperature, float soc, float chargeRate) const {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
