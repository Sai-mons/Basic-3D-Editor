#pragma once

class Render_UI {
    private:
        void Render_FRect(SDL_Renderer* renderer, const UIs_Properties& ui_info, int& color_value) {
            SDL_SetRenderDrawColor(renderer, 36, 36, 36, 255);
            SDL_FRect border_frect = {ui_info.frect.x-1, ui_info.frect.y-1, ui_info.frect.w+2, ui_info.frect.h+2};
            SDL_RenderFillRect(renderer, &border_frect);
            
            if (ui_info.hover) {color_value = 30;};

            SDL_SetRenderDrawColor(renderer, color_value, color_value, color_value, 255);
            SDL_RenderFillRect(renderer, &ui_info.frect);
            color_value = 10;
        };
    public:
        void Render(SDL_Renderer* renderer) {
            int color_value = 0;
            for (const UIs_Properties& ui_info : uis.properties) {
                Render_FRect(renderer, ui_info, color_value);
            };
        };
};

Render_UI ui_functions;