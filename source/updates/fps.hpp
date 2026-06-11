#pragma once

void Update_Fps() {
    std::chrono::duration<float> delta = high_res_clock::now() - time_data.last_time;
    time_data.delta_time = delta.count();
    
    time_data.last_time = high_res_clock::now();
    float fps = 1.0f / time_data.delta_time;

    std::string fps_title = window_data.app_title + " - FPS: " + std::to_string(static_cast<int>(fps));
    SDL_SetWindowTitle(sdl_data.window, fps_title.c_str());
};