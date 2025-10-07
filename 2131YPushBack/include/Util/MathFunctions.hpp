/**
 * @file mathFunctions.hpp
 * @author Ezra Jones (2131Y)
 * @brief 
 * @version 2.0
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <vector>
#include <numeric>


template <typename T>
T average(std::vector<T> averageValues)
{
    T summation = std::accumulate(averageValues.begin(), averageValues.end(), T(0));
    return summation / (averageValues.size());
}

