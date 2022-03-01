#include "../include/Simple_window.h"

#include <iostream>

using namespace Graph_lib;

const int width = 800;
const int height = 750; // TODO: feltöltéskor átírni 1000-re

int main() {
    Simple_window win(Point(50, 100), width, height, "Chapter 14 Drill");

    const int grid_size = 800;
    const int grid_unit_size = 100;
    Lines grid; grid.set_color(Color::black);
    for (int i = grid_unit_size; i < grid_size; i += grid_unit_size) {
        grid.add(Point(i, 0), Point(i, grid_size)); // függőleges vonalak
        grid.add(Point(0, i), Point(grid_size, i)); // vízszintes vonalak
    }
    win.attach(grid);

    Vector_ref<Rectangle> rects;
    for (int i = 0; i < grid_size; i += grid_unit_size) {
        rects.push_back(new Rectangle(Point(i,i), grid_unit_size, grid_unit_size));
        auto& r = rects[rects.size() - 1];
        r.set_color(Color::invisible); r.set_fill_color(Color::red);
        win.attach(r);
    }

    std::string img_p = "/home/klevcsoo/GitHub/deik-prog1/src/drillek/chapter13/mountains.jpg";
    Image img1(Point(0, 300), img_p); win.attach(img1);
    Image img2(Point(300, 600), img_p); win.attach(img2);
    Image img3(Point(500, 100), img_p); win.attach(img3);

    std::string shore_p = "/home/klevcsoo/GitHub/deik-prog1/src/drillek/chapter13/shore.jpg";
    Image shore_img(Point(0, 0), shore_p);
    win.attach(shore_img); win.wait_for_button();
    while (true) {
        const int coords[2] = {
            randint(grid_size / grid_unit_size) * grid_unit_size,
            randint(grid_size / grid_unit_size) * grid_unit_size
        };
        std::cout << coords[0] << ' ' << coords[1] << std::endl;
        // az Image::move valamiért mindig segmentation fault-ot okoz
        // shore_img.move(coords[0], coords[1]);
        win.wait_for_button();
    }

    win.wait_for_button();
    return 0;
}
