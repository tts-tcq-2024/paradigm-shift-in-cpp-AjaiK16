#include "ParameterCheck.h"

ParameterCheck::ParameterCheck(const RangeChecker& checker,
                               const std::string& outRangeEN, const std::string& outRangeDE,
                               const std::string& warnEN, const std::string& warnDE,
                               MessageHandler& handler)
    : rangeChecker(checker), outOfRangeMsgEN(outRangeEN), outOfRangeMsgDE(outRangeDE),
      warningMsgEN(warnEN), warningMsgDE(warnDE), messageHandler(handler) {}

bool ParameterCheck::check(float value) const {
    if (!rangeChecker.isInRange(value)) {
        messageHandler.printMessage(outOfRangeMsgEN, outOfRangeMsgDE);
        return false;
    }
    if (rangeChecker.isNearUpperLimit(value) || rangeChecker.isNearLowerLimit(value)) {
        messageHandler.printMessage(warningMsgEN, warningMsgDE);
    }
    return true;
}
