#pragma once

#include "../geometry/assembler.hpp"
#include "info.hpp"

void Init(int argc, char* argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO) || !TTF_Init()) {return;};
    sdl_data.window = SDL_CreateWindow(window_data.app_title.c_str(), window_data.window_width, window_data.window_height, 0);
    if (!sdl_data.window ) {
        SDL_Quit();
        return;
    };
    sdl_data.renderer = SDL_CreateRenderer(sdl_data.window, NULL);
    if (!sdl_data.renderer) {
        SDL_DestroyWindow(sdl_data.window);
        SDL_Quit();
        return;
    };
    
    JSON_Init();
    text.Create_Texts(sdl_data.renderer);
};