// FUNCTION GRAPHING DRILL
#include "../include/Simple_window.h"
#include "../include/Graph.h"

#include <iostream>

const int width = 600;
const int height = 600;

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main() {
    Simple_window win(Point(100, 150), width, height, "Function graphs");

    Axis x_axis(Axis::x, Point(100, 300), 400, 20, "1 == 20 pixels");
    x_axis.set_color(Color::red); win.attach(x_axis);
    Axis y_axis(Axis::y, Point(300, 500), 400, 20, "1 == 20 pixels");
    y_axis.set_color(Color::red); win.attach(y_axis);

    // ------------------------------

    const int range[2] = { -10, 11 };
    const Point origin(300, 300);
    const int num_points = 400;
    const int scale[2] = { 20, 20 };

    Function f1(one, range[0], range[1], origin, num_points, scale[0], scale[1]);
    win.attach(f1);
    Function f2(slope, range[0], range[1], origin, num_points, scale[0], scale[1]);
    win.attach(f2);
    Function f3(square, range[0], range[1], origin, num_points, scale[0], scale[1]);
    win.attach(f3);
    Function f4(cos, range[0], range[1], origin, num_points, scale[0], scale[1]);
    f4.set_color(Color::blue); win.attach(f4);
    Function f5(sloping_cos, range[0], range[1], origin, num_points, scale[0], scale[1]);
    win.attach(f5);

    win.wait_for_button();
    return 0;
}
