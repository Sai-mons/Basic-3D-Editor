#pragma once

class Button_Mouse_Check {
    private:
        void Check_Click(UIs_Properties& ui_info, bool& clicked) {
           if (clicked) {
                button_find.Function(ui_info.frect.y);
                clicked = false;
           };
        };

        void Check_Hover(UIs_Properties& ui_info, const float& mouse_x, const float& mouse_y, bool clicked) {
            if (validate.Valid_FRect(mouse_x,mouse_y,ui_info.frect) && ui_info.frect.y != 0) {
                ui_info.hover = true;
                Check_Click(ui_info,clicked);
            } else {
                ui_info.hover = false;
            };  
        };

    public:
        void Check_Action(const float& mouse_x, const float& mouse_y, bool clicked) {
            for (UIs_Properties& ui_info : uis.properties) {
                Check_Hover(ui_info,mouse_x,mouse_y,clicked);
            };
            find_selection_mode.Find(mouse_x,mouse_y,clicked);
        };
};

Button_Mouse_Check button_mouse;