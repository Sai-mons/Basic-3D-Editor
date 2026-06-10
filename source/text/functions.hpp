#pragma once

struct Text_Functions {
    void Create_Texts(SDL_Renderer* renderer) {
        texts.font1 = TTF_OpenFont("assets/fonts/Comic Sans MS.ttf", 22);
        texts.font2 = TTF_OpenFont("assets/fonts/Comic Sans MS.ttf", 17);
        texts.font3 = TTF_OpenFont("assets/fonts/Comic Sans MS.ttf", 13);

        for (auto& text_info : texts.properties) {
            SDL_Surface* surface = TTF_RenderText_Solid(*text_info.font, text_info.text.c_str(), 0, texts.color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FRect text_frect = {text_info.x, text_info.y, (float)surface->w, (float)surface->h};
            text_info.texture = texture;
            text_info.frect = text_frect;
            SDL_DestroySurface(surface);
        };

        TTF_CloseFont(texts.font1);
        TTF_CloseFont(texts.font2);
        TTF_CloseFont(texts.font3);
    };

    void Render_Texts(SDL_Renderer* renderer) { 
        for (const auto& text_info : texts.properties) {
            SDL_RenderTexture(renderer, text_info.texture, nullptr, &text_info.frect);
        };
    };
};

Text_Functions text;