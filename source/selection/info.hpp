#pragma once

enum class Selection_Type {
    Vertex,Edge,Face
};

struct Vertex_And_Edge_Selection {
    Selection_Type type;
    SDL_FRect frect{};
    float x1{},x2{},y1{},y2{};
    float tri1{},tri2{},tri3{};
    bool hover = false;
    bool selected = false;

    Vertex_And_Edge_Selection (SDL_FRect frect_2) : type(Selection_Type::Vertex), frect(frect_2) {}
    Vertex_And_Edge_Selection (float x1_2, float x2_2, float y1_2, float y2_2) : type(Selection_Type::Edge), x1(x1_2), x2(x2_2), y1(y1_2), y2(y2_2) {}
    Vertex_And_Edge_Selection (float tri_1, float tri_2, float tri_3) : type(Selection_Type::Face), tri1(tri_1), tri2(tri_2), tri3(tri_3) {}
};

struct Selections {
    bool vertex_selection = false;
    bool edge_selection = false;
    bool face_selection = false;
    std::vector<Vertex_And_Edge_Selection> selected;
};

Selections selection_list;