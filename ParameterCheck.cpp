#include "ParameterCheck.h"

ParameterCheck::ParameterCheck(const RangeChecker& checker,
                               const std::string& outRangeEN, const std::string& outRangeDE,
                               const std::string& warnEN, const std::string& warnDE,
                               MessageHandler& handler)
    : rangeChecker(checker), outOfRangeMsgEN(outRangeEN), outOfRangeMsgDE(outRangeDE),
      warningMsgEN(warnEN), warningMsgDE(warnDE), messageHandler(handler) {}

bool ParameterCheck::isOutOfRange(float value) const {
    if (!rangeChecker.isInRange(value)) {
        messageHandler.printMessage(outOfRangeMsgEN, outOfRangeMsgDE);
        return true;
    }
    return false;
}

void ParameterCheck::checkForWarnings(float value) const {
    if (rangeChecker.isNearUpperLimit(value) || rangeChecker.isNearLowerLimit(value)) {
        messageHandler.printMessage(warningMsgEN, warningMsgDE);
    }
}

bool ParameterCheck::check(float value) const {
    if (isOutOfRange(value)) {
        return false;
    }
    checkForWarnings(value);
    return true;
}
