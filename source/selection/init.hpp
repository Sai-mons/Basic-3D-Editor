#pragma once

class Selection_Init {
    private:
        void Vertex_Init() {
            selection_list.selected.clear();
            for (const Converted_Vertex& vertice : shape_converted.vertices) {
                SDL_FRect square = {vertice.x - 2.5f, vertice.y - 2.5f, 15, 15};
                selection_list.selected.emplace_back(square);
            };
        };

        void Edge_Init() {
            selection_list.selected.clear();
            for (const Edge& edge : chosen_shape.edges) {
                const Converted_Vertex& v1 =  shape_converted.vertices[edge.v1];
                const Converted_Vertex& v2 = shape_converted.vertices[edge.v2];
                selection_list.selected.emplace_back(v1.x,v2.x,v1.y,v2.y);
            };
        };

        void Face_Init() {
            selection_list.selected.clear();
            for (const Triangles& triangle : chosen_shape.faces) {
                selection_list.selected.emplace_back(triangle.t1,triangle.t2,triangle.t3);
            };
        };
    
    public:
        void Init() {
            if (selection_list.vertex_selection) {Vertex_Init();}
            else if (selection_list.edge_selection) {Edge_Init();}
            else if (selection_list.face_selection) {Face_Init();};
        };
};

Selection_Init init_select;