#pragma once

struct Vertex {
    float x,y,z;
};

struct Edge {
    int v1,v2;
};

struct Triangles {
    int t1,t2,t3;
};

struct Shape {
    std::vector<Vertex> vertices = {
    };
    
    std::vector<Edge> edges = {
    };

    std::vector<Triangles> faces = {
    };
};

Shape chosen_shape;