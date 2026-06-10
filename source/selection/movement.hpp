#pragma once

class Move_Vertex {
    private:
        void New_Pos(const int& index, const float& x, const float& y, const float& z) {
            chosen_shape.vertices[index].x = chosen_shape.vertices[index].x + x;
            chosen_shape.vertices[index].y = chosen_shape.vertices[index].y + y;
            chosen_shape.vertices[index].z = chosen_shape.vertices[index].z + z;
        };
    public:
        void Move(const float& x, const float& y, const float& z) {
            if (!selection_list.vertex_selection) {return;};
            for (int index = 0; index < (int)chosen_shape.vertices.size(); index++) {
                if (!selection_list.selected[index].selected) {continue;};
                New_Pos(index, x, y, z);
            };
        };
};

Move_Vertex move_vertex;