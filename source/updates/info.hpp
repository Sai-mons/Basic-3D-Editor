#pragma once

using high_res_clock = std::chrono::high_resolution_clock;

struct TimeData {
    float delta_time = 0.0f;
    high_res_clock::time_point last_time = high_res_clock::now();
};

struct TimeData time_data; 