#pragma once

class JSON_Functions {
    private:
        void Update() {
            std::ofstream f("memory.json");
            f << json_info.file.dump(4);
        };
    
        bool CheckUp() {
            if (json_info.file.contains("Vertices") && json_info.file.contains("Edges") && json_info.file.contains("Faces")) {
                    return true;
                } else {
                    return false;
                };
        };
    public:
        void Import() {
            if (!CheckUp()) {return;};
            chosen_shape.vertices.clear();
            chosen_shape.edges.clear();
            chosen_shape.faces.clear();

            for (const auto& vertex : json_info.file["Vertices"]) {
                chosen_shape.vertices.push_back({vertex[0],vertex[1],vertex[2]});
            };
            for (const auto& edge : json_info.file["Edges"]) {
                chosen_shape.edges.push_back({edge[0],edge[1]});
            };
            for (const auto& face : json_info.file["Faces"]) {
                chosen_shape.faces.push_back({face[0],face[1],face[2]});
            };
        };

        void Export() {
            json_info.file.clear();

            for (const Vertex& vertex : chosen_shape.vertices) {
                json_info.file["Vertices"].push_back({vertex.x, vertex.y, vertex.z});
            };
            for (const Edge& edge : chosen_shape.edges) {
                json_info.file["Edges"].push_back({edge.v1, edge.v2});
            };
            for (const Triangles& face : chosen_shape.faces) {
                json_info.file["Faces"].push_back({face.t1, face.t2, face.t3});
            };

            Update();
        };
};

JSON_Functions json_functions;