/**
 * @file Constants.hpp
 * @author Ezra Jones (2131Y)
 * @brief Useful Mathematical Constants
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

constexpr float pi = 3.14159265358979323846f;
constexpr float millis_to_sec = 0.001f;
constexpr float sec_to_millis = 1000.0f;

constexpr float min_to_sec = 60.0f;
constexpr float sec_to_min = (1.0f / 60.0f);

constexpr float rpm_to_degpsec = (360.0f / 60.0f);
constexpr float degpsec_to_rpm = (60.0f / 360.0f);

constexpr float gravity = 9.80665f;
constexpr float meters_to_inches = 39.37007874f;

constexpr float deg_to_rev = (1.0f / 360.0f);

constexpr float rad_to_deg = (180.0f / pi);
constexpr float deg_to_rad = (pi / 180.0f);