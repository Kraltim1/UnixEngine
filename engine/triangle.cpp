#include "triangle.h"

Triangle::Triangle() {
	sides = 3;
}

Triangle::~Triangle() {
}


void Triangle::set_points() {
// sets defines the points given
	int p[8] = {x+width/2,y, x,y+height, x+width,y+height, x+width/2,y};
	for (int i = 0; i < 8; i++) {
		*(points+i) = p[i];
	}
}

int Triangle::get_point(int i) {
	return *(points+i);
}

