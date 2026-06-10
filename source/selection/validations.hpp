#pragma once

struct Validation_Functions {
    bool Valid_FRect(const float& mouse_x, const float& mouse_y, const SDL_FRect& frect) {
        return (mouse_x >= frect.x && mouse_x <= frect.x + frect.w &&
                mouse_y >= frect.y && mouse_y <= frect.y + frect.h);
    };

    bool Valid_Line(const float& mouse_x, const float& mouse_y, const float& line_x1, const float& line_x2, const float& line_y1, const float& line_y2) {
        float diff_x = line_x2 - line_x1;
        float diff_y = line_y2 - line_y1;
        float length = diff_x * diff_x + diff_y * diff_y;
        if (length == 0.0f) {return false;};

        float closest_point = ((mouse_x - line_x1) * diff_x + (mouse_y - line_y1) * diff_y) / length;
        closest_point = std::clamp(closest_point, 0.0f, 1.0f);
        float closest_x = line_x1 + closest_point * diff_x;
        float closest_y = line_y1 + closest_point * diff_y;
        
        float distance = 
            std::sqrt(
                (mouse_x - closest_x) * (mouse_x - closest_x) + (mouse_y - closest_y) * (mouse_y - closest_y)
            );
        return distance <= 5.0f;
    };

    bool Valid_Geometry(const float& mouse_x, const float& mouse_y, const float& v1_x, const float& v1_y, const float& v2_x, const float& v2_y, const float& v3_x, const float& v3_y) {
        float line_1 = (mouse_x - v3_x) * (v2_y - v3_y) - (v2_x - v3_x) * (mouse_y - v3_y);
        float line_2 = (mouse_x - v1_x) * (v3_y - v1_y) - (v3_x - v1_x) * (mouse_y - v1_y);
        float line_3 = (mouse_x - v2_x) * (v1_y - v2_y) - (v1_x - v2_x) * (mouse_y - v2_y);

        bool all_pos = (line_1 < 0 && line_2 < 0 && line_3 < 0);
        bool all_neg = (line_1 > 0 && line_2 > 0 && line_3 > 0);

        return (all_pos || all_neg);
    };

    int Vertex_or_Edge_Selection(const Vertex_And_Edge_Selection& target) {
        if (target.type == Selection_Type::Vertex) {return 1;}
        else if (target.type == Selection_Type::Edge) {return 2;}
        else if (target.type == Selection_Type::Face) {return 3;}
        else {return 0;};
    };
};

Validation_Functions validate;