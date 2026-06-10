#pragma once

struct Window_Configs {
    const std::string app_title = "Render3D";
    const int window_width = 800;
    const int window_height = 600;
};

struct Window_Configs window_data;

struct SDL_Info {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool app_running = true;
};

struct SDL_Info sdl_data;