#pragma once

class Find_Selection {
    private:
        void Is_Vertex(const float& mouse_x, const float& mouse_y, const bool& clicked) {
            if (!selection_list.vertex_selection) {Is_Edge(mouse_x, mouse_y, clicked); return;};
            select_element.Select(mouse_x,mouse_y,clicked);
            uis.properties[4].hover = true;
        };

        void Is_Edge(const float& mouse_x, const float& mouse_y, const bool& clicked) {
            if (!selection_list.edge_selection) {Is_Face(mouse_x, mouse_y, clicked); return;};
            select_element.Select(mouse_x,mouse_y,clicked);
            uis.properties[7].hover = true;
        };

        void Is_Face(const float& mouse_x, const float& mouse_y, const bool& clicked) {
            if (!selection_list.face_selection) {return;};
            select_element.Select(mouse_x,mouse_y,clicked);
            uis.properties[10].hover = true;
        };

    public:
        void Find(const float& mouse_x, const float& mouse_y, const bool& clicked) {
            if (clicked && selection_list.selected.empty()) {return;};
            Is_Vertex(mouse_x,mouse_y,clicked);
        };
};

Find_Selection find_selection_mode;