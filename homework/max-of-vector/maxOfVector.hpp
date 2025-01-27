#pragma once
#include <limits>
#include <vector>

int maxOfVector(const std::vector<int>& vec) {
    int maxVal = vec[0];
    for (auto val : vec) {
        if (val >= maxVal)
            maxVal = val;
    }
    return maxVal;
}

