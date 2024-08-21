
#ifndef PARAMETER_CHECK_H
#define PARAMETER_CHECK_H

#include "RangeChecker.h"
#include "MessageHandler.h"

class ParameterCheck {
    RangeChecker rangeChecker;
    std::string outOfRangeMsgEN;
    std::string outOfRangeMsgDE;
    std::string warningMsgEN;
    std::string warningMsgDE;
    MessageHandler& messageHandler;

public:
    ParameterCheck(const RangeChecker& checker,
                   const std::string& outRangeEN, const std::string& outRangeDE,
                   const std::string& warnEN, const std::string& warnDE,
                   MessageHandler& handler);

    bool check(float value) const;
};

#endif // PARAMETER_CHECK_H
