#include "../include/Simple_window.h"

#include <iostream>

int main(int argc, char** argv) {
  Simple_window window(Graph_lib::Point(100, 100), 600, 400, "My Window");
  window.wait_for_button();

  return 0;
}
