#pragma once

#include "../camera/assembler.hpp"
#include "../geometry/assembler.hpp"
#include "../renderer/projection.hpp"
#include "../ui/assembler.hpp"
#include "../buttons/assembler.hpp"
#include "../selection/assembler.hpp"
#include "../geometry/defaults.hpp"
#include "../json/assembler.hpp"
#include "../text/assembler.hpp"
#include "../display/assembler.hpp"
#include "../start/assembler.hpp"

void Update_Screen() {
    if (!sdl_data.renderer) {return;};
    convert.Convert();

    SDL_SetRenderDrawColor(sdl_data.renderer, 5, 5, 5, 255);
    SDL_RenderClear(sdl_data.renderer);

    display.Draw(sdl_data.renderer);

    ui_functions.Render(sdl_data.renderer);
    text.Render_Texts(sdl_data.renderer);
    SDL_RenderPresent(sdl_data.renderer);
};