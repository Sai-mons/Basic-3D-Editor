#pragma once

struct Create_Element {
    void Create_Vertex() {
        chosen_shape.vertices.push_back({0,0,0});
    };

    void Create_Edge() {
        if (!selection_list.vertex_selection) {return;};
        std::vector<int> selected_indices;
        int selected_size = (int)selection_list.selected.size();

        for (int index = 0; index < selected_size; index++) {
            if (selection_list.selected[index].selected) {selected_indices.push_back(index);};
        };
        if (selected_indices.size() < 2) {return;};

        for (int index = 0; index < (int)selected_indices.size() - 1; index++) {
            chosen_shape.edges.push_back({selected_indices[index], selected_indices[index + 1]});
        };
        chosen_shape.edges.push_back({selected_indices.back(), selected_indices.front()});
    };

    void Create_Face() {
        if (!selection_list.vertex_selection) {return;};
        std::vector<int> selected_indices;
        int selected_size = (int)selection_list.selected.size();

        for (int index = 0; index < selected_size; index++) {
            if (selection_list.selected[index].selected) {selected_indices.push_back(index);};
        };
        if (selected_indices.size() < 3) {return;};

        int first_selected = selected_indices[0];
        for (int index = 1; index < (int)selected_indices.size() - 1; index++) {
            int medium_vertex = selected_indices[index];
            int last_vertex = selected_indices[index + 1];

            const Converted_Vertex& v1 = shape_converted.vertices[first_selected];
            const Converted_Vertex& v2 = shape_converted.vertices[medium_vertex];
            const Converted_Vertex& v3 = shape_converted.vertices[last_vertex];

            float area = (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);
            if (area < 0) {std::swap(medium_vertex, last_vertex);};

            chosen_shape.faces.push_back({first_selected, medium_vertex, last_vertex});
        };
    };
};

Create_Element mesh_new;