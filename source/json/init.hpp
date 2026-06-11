#pragma once

struct JSON_Info {
    json file;
};

JSON_Info json_info;

void JSON_Init() {
    std::ifstream f("memory.json");

    if (!f.is_open()) {
        json info = json::object();
        std::ofstream new_file("memory.json");
        new_file << info.dump(4);
        json_info.file = info;
    } else {
        json info;
        try {f >> info;}
        catch (...) {info = json::object();};
        json_info.file = info;
    };
};