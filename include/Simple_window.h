#include "GUI.h"

using namespace Graph_lib;

struct Simple_window : Graph_lib::Window {
	Simple_window(Point xy, int w, int h, const string& title );

	bool wait_for_button();

	Button next_button;

private:
	bool button_pushed;
	
	static void cb_next(Address, Address addr);

	void next();

};
