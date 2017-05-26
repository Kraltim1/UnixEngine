#include "polygon.h"

// TODO: add more polygon types
Polygon::Polygon() {
	sides = 0;
}

Polygon::~Polygon() {
}


bool Polygon::isInside(int n, int canvas_x, int canvas_y) {
	bool ans = true;
	for (int i = 0; i < 2*n; i+=2) {
		int deltax = get_point(2+i)-get_point(i);
		int deltay = get_point(3+i)-get_point(1+i);

		if ( (deltax*( canvas_y-get_point(1+i) )) > (deltay*( canvas_x-get_point(i) )) ) {
			ans = false;
			break;
		}
	}
	return ans;
}

string Polygon::draw(int canvas_x, int canvas_y) {
	set_points();

    stringstream ss;

    if (isInside(sides, canvas_x, canvas_y)) {
    // fill in polygon
        ss << background_color << style << "\033[0m";
    }

    // Filter out the borders and draw the corresponding pixels
//    if (canvas_x - x < border_width || x + width - canvas_x <= border_width) {
//        ss << border_color << border_style << "\033[0m";
//    }
//    else if (canvas_y - y < border_width || y + height - canvas_y <= border_width)
//        ss << border_color << border_style << "\033[0m";

    return ss.str();
}
