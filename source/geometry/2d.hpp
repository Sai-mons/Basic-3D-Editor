#pragma once

struct Converted_Vertex {
    float x,y;
};

struct Converted_Shape {
    std::vector<Converted_Vertex> vertices;
};

Converted_Shape shape_converted;