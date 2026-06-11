#pragma once

class Select_Mesh_Element {
    private:
        void Hover_And_Click(Vertex_And_Edge_Selection& target, const bool& click) {
            target.hover = true;
            if (click) {target.selected = true;};
        };

        void Vertex(Vertex_And_Edge_Selection& vertex, const int& mouse_x, const int& mouse_y, const bool& click) {
            if (validate.Valid_FRect(mouse_x,mouse_y,vertex.frect)) {Hover_And_Click(vertex,click);}
            else {vertex.hover = false;};
        };

        void Edge(Vertex_And_Edge_Selection& edge, const int& mouse_x, const int& mouse_y, const bool& click) {
            if (validate.Valid_Line(mouse_x,mouse_y,edge.x1,edge.x2,edge.y1,edge.y2)) {Hover_And_Click(edge,click);}
            else {edge.hover = false;};
        };

        void Face(Vertex_And_Edge_Selection& face, const int& mouse_x, const int& mouse_y, const bool& click) {
            const Converted_Vertex& triangle_1 = shape_converted.vertices[face.tri1];
            const Converted_Vertex& triangle_2 = shape_converted.vertices[face.tri2];
            const Converted_Vertex& triangle_3 = shape_converted.vertices[face.tri3];

            float area = (triangle_2.x - triangle_1.x) * (triangle_3.y - triangle_1.y) - (triangle_2.y - triangle_1.y) * (triangle_3.x - triangle_1.x);
            if (area < 0) {return;};

            if (validate.Valid_Geometry(mouse_x,mouse_y,triangle_1.x,triangle_1.y,triangle_2.x,triangle_2.y,triangle_3.x,triangle_3.y)) {Hover_And_Click(face,click);}
            else {face.hover = false;};  
        };
    public:
        void Select(const int& mouse_x, const int& mouse_y, const bool& click) {
            for (Vertex_And_Edge_Selection& element : selection_list.selected) {
                const int& type = validate.Vertex_or_Edge_Selection(element);

                if (type == 1 && selection_list.vertex_selection) {Vertex(element, mouse_x, mouse_y, click);}
                else if (type == 2 && selection_list.edge_selection) {Edge(element, mouse_x, mouse_y, click);}
                else if (type == 3 && selection_list.face_selection) {Face(element, mouse_x, mouse_y, click);};
            };
        };
};

Select_Mesh_Element select_element;