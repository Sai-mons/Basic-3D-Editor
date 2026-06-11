#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>
#include <vector>
#include <algorithm>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "../lib/nlohmann_json/json.hpp"

#include "manager.hpp"
#include "../updates/assembler.hpp"

int main(int argc, char* argv[]) {
    Init(argc,argv);
    update_loop.Run_Update_Loop();
    
    SDL_DestroyWindow(sdl_data.window);
    SDL_DestroyRenderer(sdl_data.renderer);
    SDL_Quit();
    TTF_Quit();
    return 0;
};