#include <iostream>
#include <cmath>

int main() {
    const double A = 0.1, B = 0.2;
    const char* donut_chars = ".,-~:;=!*#$@";
    const int num_chars = 12;
    const int width = 80, height = 24;
    const int half_width = width / 2, half_height = height / 2;
    const double max_radius = half_height * 0.9;

    while (true) {
        double time = 0.0;
        double cos_t = 0.0, sin_t = 0.0;
        double cos_p = 0.0, sin_p = 0.0;
        char output[height][width + 1];

        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                output[j][i] = ' ';
            }
            output[j][width] = '\0';
        }

        for (int i = 0; i < 628; i++) {
            time += 0.04;
            cos_t = cos(time);
            sin_t = sin(time);
            cos_p = cos(i * 0.04);
            sin_p = sin(i * 0.04);

            double x = cos_t;
            double y = sin_t;
            double z = cos_p + 2;
            double inv_z = 1 / z;
            double xp = x * inv_z;
            double yp = y * inv_z;
            int x_pixel = static_cast<int>(half_width + xp * half_width);
            int y_pixel = static_cast<int>(half_height + yp * half_height);
            double radius = sqrt(x * x + y * y);

            if (radius < max_radius) {
                int index = static_cast<int>(radius / max_radius * num_chars);
                output[y_pixel][x_pixel] = donut_chars[index];
            }
        }

        std::cout << "\033[H";
        for (int j = 0; j < height; j++) {
            std::cout << output[j] << '\n';
        }
        std::cout.flush();
    }

    return 0;
}