#ifndef BMS_H
#define BMS_H

#include <string>

enum class Language { ENGLISH, GERMAN };

class BatteryManagementSystem {
public:
    BatteryManagementSystem(Language lang = Language::ENGLISH);

    void setLanguage(Language lang);

    bool isTemperatureOk(float temperature) const;

    bool isSocOk(float soc) const;

    bool isChargeRateOk(float chargeRate) const;

    bool batteryIsOk(float temperature, float soc, float chargeRate) const;

private:
    bool isInRange(float value, float min, float max) const;
    bool isBelowThreshold(float value, float max) const;
    bool checkRangeAndReport(float value, float min, float max, const std::string& warningMsg, const std::string& breachMsg) const;
    bool checkMaxAndReport(float value, float max, const std::string& warningMsg, const std::string& breachMsg) const;

    std::string translateMessage(const std::string& key) const;

    Language currentLanguage;
    std::map<Language, std::map<std::string, std::string>> messages;
};

#endif // BMS_H
