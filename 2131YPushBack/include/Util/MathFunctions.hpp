/**
 * @file mathFunctions.hpp
 * @author Ezra Jones (2131Y)
 * @brief Useful Math Functions
 * @version 2.0
 * @date 2025-10-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <numeric>
#include <vector>

/**
 * @brief Templated Average Function
 * 
 * @tparam T 
 * @param vector 
 * @return T 
 */
template <typename T>
T average(std::vector<T> vector)
{
  	T summation = std::accumulate(vector.begin(), vector.end(), T(0));
  	return summation / static_cast<T>(vector.size());
}


template <typename T>
T sign(T value)
{
	if (value > 0.0f)
		return 1.0f;
	else if (value < 0.0f)
		return -1.0f;
	else
		return value;
}

