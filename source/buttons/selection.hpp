#pragma once

void Change_Selection(bool& selection) {
    bool newvalue = !selection;
    selection_list.vertex_selection = false;
    selection_list.edge_selection = false;
    selection_list.face_selection = false;
    selection = newvalue;
    init_select.Init();
};