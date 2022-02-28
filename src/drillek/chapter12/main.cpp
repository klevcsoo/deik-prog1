#include "../include/Simple_window.h"

#include <iostream>

using namespace Graph_lib;

int main(int argc, char** argv) {
  Simple_window window(Point(100, 100), 600, 400, "My Window");

  Axis xa(Axis::x, Point(20, 350), 280, 10, "x axis");
  Axis ya(Axis::y, Point(20, 350), 280, 10, "y axis");
  window.attach(xa); window.attach(ya);

  Rectangle r(Point(200, 200), 100, 50);
  r.set_fill_color(Color::green);
  window.attach(r);

  Text t(Point(200, 150), "Hello Graphics");
  t.set_font_size(24);
  t.set_font(Graph_lib::Font::helvetica_bold);
  window.attach(t);

  // Ez volt hirtelen a letöltések mappában
  std::string imgp = "/home/klevcsoo/GitHub/deik-prog1/src/drillek/chapter12/raspi_logo.jpg";
  Image img(Point(100, 100), imgp);
  window.attach(img);

  Circle c(Point(300, 300), 100);
  window.attach(c);

  Ellipse e(Point(550, 350), 100, 50);
  e.set_fill_color(Color::dark_blue);
  window.attach(e);

  window.wait_for_button();
  return 0;
}
