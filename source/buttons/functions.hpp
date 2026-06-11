#pragma once

class Check_Selection {
    private:
        float identifier = 0;

        void Change_Shape() {
            if (identifier == 25.0) {json_functions.Export();}
            else if (identifier == 50.0) {json_functions.Import();}
            else if (identifier == 75.0) {mesh_destroy.Clear_Geometry();};
        };

        void Updating() {
            if (identifier == 55.0) {set_mesh.Square_Mesh();}
            else if (identifier == 85.0) {set_mesh.Pyramid_Mesh();}
            else if (identifier == 115.0) {set_mesh.Sphere_Mesh();};
        };

        void Selecting() {
            if (identifier == 195.0) {Change_Selection(selection_list.vertex_selection);}
            else if (identifier == 345.0) {Change_Selection(selection_list.edge_selection);}
            else if (identifier == 495.0) {Change_Selection(selection_list.face_selection);};
        };

        void Destroying() {
            if (identifier == 230.0 && selection_list.vertex_selection ||
                identifier == 380.0 && selection_list.edge_selection ||
                identifier == 530.0 && selection_list.face_selection) {
                mesh_destroy.Destroy_Selected();
            };
        };

        void Creating() {
            if (identifier == 265.0) {mesh_new.Create_Vertex();}
            else if (identifier == 415.0) {mesh_new.Create_Edge();}
            else if (identifier == 565.0) {mesh_new.Create_Face();};
        };
    public:
        void Function(const int& id) {
            identifier = id;
            Change_Shape();
            Updating();
            Selecting();
            Destroying();
            Creating();
        };
};

Check_Selection button_find;