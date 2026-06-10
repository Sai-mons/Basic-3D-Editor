#pragma once

class Display_Selection_Checks {
    private:
        void Change_Color(SDL_Renderer* renderer, const Vertex_And_Edge_Selection& target, const Color_Structures& color)  {
            if (target.selected) {
                SDL_SetRenderDrawColor(renderer, color.select.r, color.select.g, color.select.b, color.select.a);
                if (target.type == Selection_Type::Face) {colors.Current_Face_Color = colors.face_color.select;};
            } else if (target.hover) {
                SDL_SetRenderDrawColor(renderer, color.hover.r, color.hover.g, color.hover.b, color.hover.a);
                if (target.type == Selection_Type::Face) {colors.Current_Face_Color = colors.face_color.hover;};
            };
        };

        void Choose_Type(SDL_Renderer* renderer, const Vertex_And_Edge_Selection& target, const int& type) {
            if (type == 1) {
                Change_Color(renderer, target, colors.vertex_color);
            } else if (type == 2) {
                Change_Color(renderer, target, colors.edge_color);
            } else if (type == 3) {
                Change_Color(renderer, target , colors.face_color);
            };
        };

    public:
        void Check_Hover_And_Click_Selection(SDL_Renderer* renderer, const int& index) {
            Vertex_And_Edge_Selection target = selection_list.selected[index];
            int type = validate.Vertex_or_Edge_Selection(target);
            Choose_Type(renderer,target,type);
        };
};

Display_Selection_Checks change_colors;