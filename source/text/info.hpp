#pragma once

struct Text_Properties {
    std::string text;
    TTF_Font** font;
    float x;
    float y;
    SDL_FRect frect;
    SDL_Texture* texture;
};

struct SideBar_Texts {
    TTF_Font* font1 = nullptr;
    TTF_Font* font2 = nullptr;
    TTF_Font* font3 = nullptr;
    SDL_Color color = {255, 255, 255, 255};

    std::vector<Text_Properties> properties = {
        {"— Menu —", &font1, 20.0f, 10.0f},

        {"Save", &font3, 735.0f, 25.0f},
        {"Load", &font3, 735.0f, 50.0f},
        {"Clear", &font3, 735.0f, 75.0f},

        {"Load Cube", &font3, 40.0f, 55.0f},
        {"Load Pyramid", &font3, 35.0f, 85.0f},
        {"Load Sphere", &font3, 35.0f, 115.0f},

        {"*Vertices", &font2, 15.0f, 155.0f},
        {"Select Vertex", &font3, 29.0f, 195.0f},
        {"Destroy Vertex", &font3, 27.0f, 230.0f},
        {"Create Vertex", &font3, 29.0f, 265.0f},

        {"*Edges", &font2, 15.0f, 305.0f},
        {"Select Edge", &font3, 34.0f, 345.0f},
        {"Destroy Edge", &font3, 32.0f, 380.0f},
        {"Create Edge", &font3, 34.0f, 415.0f},

        {"*Faces", &font2, 15.0f, 455.0f},
        {"Select Face", &font3, 34.0f, 495.0f},
        {"Destroy Face", &font3, 32.0f, 530.0f},
        {"Create Face", &font3, 34.0f, 565.0f},
    };
};

SideBar_Texts texts;