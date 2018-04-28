#include "triangle.h"

Triangle::Triangle() {
	sides = 3;
}

Triangle::~Triangle() {
}


void Triangle::set_points() {
// sets defines the points given
	points_not_set = false;

	int p[16] = {x+width/2,y, x,y+height, x+width,y+height, x+width/2,y,
				(x+border_width)+(width-2*border_width)/2,(+border_width), (x+border_width),(y+border_width)+(height-2*border_width), (x+border_width)+(width-2*border_width),(y+border_width)+(height-2*border_width), (x+border_width)+(width-2*border_width)/2,y};
	for (int i = 0; i < 16; i++) {
		*(points+i) = p[i];
	}

	for (int i = 0; i < 16; i += 2) {
		cout << i/2 << ": (" << *(points+i) << "," << *(points+i+1) << ")" << endl;
	}
}

int Triangle::get_point(int i) {
	return *(points+i);
}

