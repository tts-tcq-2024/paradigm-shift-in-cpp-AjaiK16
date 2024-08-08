#ifndef RANGE_CHECKER_H
#define RANGE_CHECKER_H

class RangeChecker {
    float min;
    float max;
    float warningTolerance;

public:
    RangeChecker(float min, float max, float tolerance)
        : min(min), max(max), warningTolerance(tolerance) {}

    bool isInRange(float value) const {
        return value >= min && value <= max;
    }

    bool isNearUpperLimit(float value) const {
        return value >= max - warningTolerance;
    }

    bool isNearLowerLimit(float value) const {
        return value <= min + warningTolerance;
    }
};

#endif // RANGE_CHECKER_H
