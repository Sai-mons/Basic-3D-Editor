#pragma once

struct Square {
    std::vector<Vertex> vertices = {
        {-100,-100,-100},
        {100,-100,-100},
        {100, 100,-100},
        {-100, 100,-100},
        {-100,-100, 100},
        {100,-100, 100},
        {100, 100, 100},
        {-100, 100, 100},
    };
    std::vector<Edge> edges = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    std::vector<Triangles> faces = {
        {0,1,2},{0,2,3},
        {4,6,5},{4,7,6},
        {0,3,7},{0,7,4},
        {1,5,6},{1,6,2},
        {3,2,6},{3,6,7},
        {0,4,5},{0,5,1},
    };
};

Square square_struct;

struct Pyramid {
    std::vector<Vertex> vertices = {
        {-100, 0, -100}, 
        {100, 0, -100},
        {100, 0,  100},
        {-100, 0,  100},
        {0, 150, 0},
    };

    std::vector<Edge> edges = {
        {0,1},{1,2},{2,3},{3,0},
        {0,4},{1,4},{2,4},{3,4},
    };

    std::vector<Triangles> faces = {
        {0,1,2},{0,2,3},
        {0,1,4},{1,2,4},    
        {2,3,4},{3,0,4},
    };
};

Pyramid pyramid_struct;

struct Reset_Mesh {
    void Square_Mesh() {
        chosen_shape.vertices = square_struct.vertices;
        chosen_shape.edges = square_struct.edges;
        chosen_shape.faces = square_struct.faces;
        init_select.Init();
    };

    void Pyramid_Mesh() {
        chosen_shape.vertices = pyramid_struct.vertices;
        chosen_shape.edges = pyramid_struct.edges;
        chosen_shape.faces = pyramid_struct.faces;
        init_select.Init();
    };

    void Sphere_Mesh() {
        chosen_shape.vertices.clear();
        chosen_shape.edges.clear();
        chosen_shape.faces.clear(); 

        const float radius = 100.0f;
        const float pi = 3.1415f;
        int slices = 8;
        int stack = 8;
        int row_size = slices + 1;

        for (int index = 0; index <= stack; index++) {
            float phi = pi * index / stack;
            
            for (int index_2 = 0; index_2 <= slices; index_2++) {
                float theta = 2.0f * pi * index_2 / 8.0f;

                float x = radius * sinf(phi) * cosf(theta);
                float y = radius * cosf(phi);
                float z = radius * sinf(phi) * sinf(theta);
                chosen_shape.vertices.push_back({x, y, z});
            };
        };

        for (int index = 0; index < (int)chosen_shape.vertices.size(); index++) {
            if ((index % row_size) != slices) {chosen_shape.edges.push_back({index, index + 1});};
            if ((index + row_size) < (int)chosen_shape.vertices.size()) {chosen_shape.edges.push_back({index, index + row_size});};
        };

        for (int index = 0; index < stack; index++) {
            for (int index_2 = 0; index_2 < slices; index_2++) {
                int first = index * row_size + index_2;
                int second = first + row_size;

                chosen_shape.faces.push_back({first, second, first + 1});
                chosen_shape.faces.push_back({second, second + 1, first + 1});
            };
        };
        init_select.Init();
    };
};

Reset_Mesh set_mesh;