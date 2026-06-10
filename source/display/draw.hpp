#pragma once

class Draw_Elements {
    private:
        void Draw_Vertices(SDL_Renderer* renderer) {
            int index = 0;

            for (const Converted_Vertex& vertice : shape_converted.vertices) {
                SDL_FRect square = {vertice.x - 2.75f, vertice.y - 2.75f, 7.5, 7.5};
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

                if (selection_list.vertex_selection && index < selection_list.selected.size()) {
                    selection_list.selected[index].frect = square;
                    change_colors.Check_Hover_And_Click_Selection(renderer,index);
                };

                SDL_RenderFillRect(renderer, &square);
                index++;
            };
        };

        void Draw_Edges(SDL_Renderer* renderer) {
            int index = 0;

            for (const Edge& edge : chosen_shape.edges) {
                Converted_Vertex& v1 =  shape_converted.vertices[edge.v1];
                Converted_Vertex& v2 = shape_converted.vertices[edge.v2];
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); 

                if (selection_list.edge_selection && index < selection_list.selected.size()) {
                    selection_list.selected[index].x1 = v1.x;
                    selection_list.selected[index].x2 = v2.x;
                    selection_list.selected[index].y1 = v1.y;
                    selection_list.selected[index].y2 = v2.y;
                    change_colors.Check_Hover_And_Click_Selection(renderer,index);
                };

                SDL_RenderLine(renderer,v1.x,v1.y,v2.x,v2.y);
                index++;
            };
        };

        void Draw_Faces(SDL_Renderer* renderer) {
            int index = 0;

            for (const Triangles& triangle : chosen_shape.faces) {
                SDL_Vertex triangle_verts[3];

                Converted_Vertex& t1 = shape_converted.vertices[triangle.t1];
                Converted_Vertex& t2 = shape_converted.vertices[triangle.t2];
                Converted_Vertex& t3 = shape_converted.vertices[triangle.t3];

                float area = (t2.x - t1.x) * (t3.y - t1.y) - (t2.y - t1.y) * (t3.x - t1.x);
                if (area < 0) {index++; continue;};

                triangle_verts[0].position = {t1.x, t1.y};
                triangle_verts[1].position = {t2.x, t2.y};
                triangle_verts[2].position = {t3.x, t3.y};
                colors.Current_Face_Color = colors.face_color.none;

                if (selection_list.face_selection && index < selection_list.selected.size()) {
                    selection_list.selected[index].tri1 = triangle.t1;
                    selection_list.selected[index].tri2 = triangle.t2;
                    selection_list.selected[index].tri3 = triangle.t3;
                    change_colors.Check_Hover_And_Click_Selection(renderer,index);
                };

                SDL_FColor chosen_color = {colors.Current_Face_Color.r / 255.0f,colors.Current_Face_Color.g / 255.0f,colors.Current_Face_Color.b / 255.0f,colors.Current_Face_Color.a / 255.0f};
                triangle_verts[0].color = chosen_color;
                triangle_verts[1].color = chosen_color;
                triangle_verts[2].color = chosen_color;

                SDL_RenderGeometry(renderer,nullptr,triangle_verts,3,nullptr,0);
            };  
        };
    public:
        void Draw(SDL_Renderer* renderer) {
            Draw_Faces(renderer);
            Draw_Edges(renderer);
            Draw_Vertices(renderer);
        };
};

Draw_Elements display;