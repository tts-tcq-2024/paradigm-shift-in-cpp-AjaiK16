
#ifndef RANGE_CHECKER_H
#define RANGE_CHECKER_H

class RangeChecker {
    float min;
    float max;
    float warningTolerance;

public:
    RangeChecker(float min, float max, float tolerance);
    bool isInRange(float value) const;
    bool isNearUpperLimit(float value) const;
    bool isNearLowerLimit(float value) const;
};

#endif // RANGE_CHECKER_H
