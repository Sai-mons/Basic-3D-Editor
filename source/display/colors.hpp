#pragma once

struct Color_Structures {
    SDL_Color hover;
    SDL_Color select;
    SDL_Color none;
};

struct Mesh_Colors {
    const Color_Structures vertex_color = {{200,0,0,255},{150,0,0,255},{0,0,0,0}};
    const Color_Structures edge_color = {{0,0,100,255},{0,0,50,255},{0,0,0,0}};
    const Color_Structures face_color = {{90,90,90,255},{60,60,60,255},{120,120,120,255}};
    SDL_Color Current_Face_Color = face_color.none;
};

Mesh_Colors colors;