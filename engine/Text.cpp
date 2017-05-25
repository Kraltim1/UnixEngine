#include "Text.h"

Text::Text() : View() {
	width = 0;
	height = 0;
}

Text::~Text() {
}

void Text::set_text(string input) {
	text = input;
	style = ' ';
}

string Text::get_text() {
	return text;
}

string Text::draw(int canvas_x, int canvas_y) {
    stringstream ss;
    int textStart = width/2+x-text.length()/2-1;

    if (!width) width=text.length();
    if (!height) height=1;

	// Filter out the borders and draw the corresponding pixels
	if (canvas_x - x < border_width || x + width - canvas_x <= border_width) {
		ss << border_color << border_style << "\033[0m";
	}
	else if (canvas_y - y < border_width || y + height - canvas_y <= border_width)
		ss << border_color << border_style << "\033[0m";
	// check if at the centre row, if at the centre of the row, write text
	else if (canvas_y == height/2+y) {
		if (canvas_x < textStart + text.length() && canvas_x >= textStart) {
			ss << background_color << text[canvas_x-textStart] << "\033[0m";
		}
		else {
			ss << background_color << style << "\033[0m";
		}
	}
	else {
		// If not a border pixel, draw a body pixel
		ss << background_color << style << "\033[0m";
	}
    return ss.str();
}
