#pragma once

class Convertor {
    private:
        Vertex Rotate(Vertex relative_vertice) {
            float cosX = std::cos(camera_data.angleX);
            float sinX = std::sin(camera_data.angleX);

            float y = relative_vertice.y * cosX - relative_vertice.z * sinX;
            float z = relative_vertice.y * sinX + relative_vertice.z * cosX;
            relative_vertice.y = y;
            relative_vertice.z = z;

            float cosY = std::cos(camera_data.angleY);
            float sinY = std::sin(camera_data.angleY);

            float x = relative_vertice.x * cosY + relative_vertice.z * sinY;
            z = -relative_vertice.x * sinY + relative_vertice.z * cosY;
            relative_vertice.x = x;
            relative_vertice.z = z;
            return relative_vertice;
        };

    public:
        void Convert(){
            shape_converted.vertices.clear();
            for (Vertex vertice : chosen_shape.vertices) {
                vertice.x = vertice.x / 4;
                vertice.y = vertice.y / 4;
                vertice.z = vertice.z / 4;

                vertice = Rotate(vertice);
                float z_check = vertice.z + camera_data.camZ;
                if (z_check < 0.1f) {z_check = 0.1f;};

                float modifier = 200.0f / z_check;
                shape_converted.vertices.push_back(
                    {vertice.x * modifier + 400 + camera_data.camX,
                    vertice.y * modifier + 300 + camera_data.camY}
                );
            };
        };
};

Convertor convert;