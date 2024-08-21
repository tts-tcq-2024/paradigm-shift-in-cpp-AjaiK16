
#include "RangeChecker.h"

RangeChecker::RangeChecker(float min, float max, float tolerance)
    : min(min), max(max), warningTolerance(tolerance) {}

bool RangeChecker::isInRange(float value) const {
    return value >= min && value <= max;
}

bool RangeChecker::isNearUpperLimit(float value) const {
    return value >= max - warningTolerance;
}

bool RangeChecker::isNearLowerLimit(float value) const {
    return value <= min + warningTolerance;
}
