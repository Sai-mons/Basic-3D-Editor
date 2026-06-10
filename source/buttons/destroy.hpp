#pragma once

class Destroy_Element {
    private:
        void Clean_Edges(const int& index) {
            for (int index2 = (int)chosen_shape.edges.size() - 1; index2 >= 0; index2--) {
                if (chosen_shape.edges[index2].v1 == index || chosen_shape.edges[index2].v2 == index) {
                    chosen_shape.edges.erase(chosen_shape.edges.begin() + index2);
                };
            };
        };

        void Clean_Faces(const int& index) {
            for (int index2 = (int)chosen_shape.faces.size() - 1; index2 >= 0; index2--) {
                if (chosen_shape.faces[index2].t1 == index || chosen_shape.faces[index2].t2 == index || chosen_shape.faces[index2].t3 == index) {
                    chosen_shape.faces.erase(chosen_shape.faces.begin() + index2);
                };
            };
        };

        void Adjust_Edges_And_Faces(const int& index) {
            for (auto& edges : chosen_shape.edges) {
                if (edges.v1 > index) edges.v1--;
                if (edges.v2 > index) edges.v2--;
            };

            for (auto& faces : chosen_shape.faces) {
                if (faces.t1 > index) faces.t1--;
                if (faces.t2 > index) faces.t2--;
                if (faces.t3 > index) faces.t3--;
            };
        };

        void Destroy(const int& index) {
            selection_list.selected.erase(selection_list.selected.begin() + index);

            if (selection_list.vertex_selection) {
                chosen_shape.vertices.erase(chosen_shape.vertices.begin() + index);
                Clean_Edges(index);
                Clean_Faces(index);
                Adjust_Edges_And_Faces(index);
            } else if (selection_list.edge_selection) {
                chosen_shape.edges.erase(chosen_shape.edges.begin() + index);
            };
            if (selection_list.face_selection) {
                chosen_shape.faces.erase(chosen_shape.faces.begin() + index);
            };
        };

    public:
        void Destroy_Selected() {
            for (int index = (int)selection_list.selected.size() - 1; index >= 0; index--) {
                if (!selection_list.selected[index].selected) {continue;};
                Destroy(index);
            };
        };

        void Clear_Geometry() {
            chosen_shape.vertices.clear();
            chosen_shape.edges.clear();
            chosen_shape.faces.clear();
        };
};

Destroy_Element mesh_destroy;