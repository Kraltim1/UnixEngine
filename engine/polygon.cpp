#include "polygon.h"

// TODO: add more polygon types
Polygon::Polygon() {
	sides = 0;

//	cout << "(" << *(points+0) << "," << *(points+1) << "), ";
//	cout << "(" << *(points+2) << "," << *(points+3) << "), ";
//	cout << "(" << *(points+4) << "," << *(points+5) << ")" << endl;
}

Polygon::~Polygon() {
}

bool Polygon::isInside(int n, int canvas_x, int canvas_y) {
	bool ans = true;
	for (int i = 0; i < 2*n; i+=2) {
		int deltax = points[2+i]-points[0+i];
		int deltay = points[3+i]-points[1+i];

//		cout << "delta x = " << deltax << endl;
//		cout << "delta y = " << deltay << endl;

//		cout << "i " << i << " --> " << ( points[2+i]-points[0+i] )*( canvas_y-points[1+i] ) << " <= " << ( points[3+i]-points[1+i] )*( canvas_x-points[0+i] ) << endl;
//		if ( ( *(points+i + 2)-*(points+i + 0) )*( canvas_y-*(points+i + 1) ) > ( *(points+i + 3)-*(points+i + 1) )*( canvas_x-*(points+i + 0) ) ) {
		if ( (deltax*( canvas_y-points[1+i] )) > (deltay*( canvas_x-points[0+i] )) ) {
			ans = false;
			break;
		}
//		cout << ans << endl;
	}
//	cout << "x: " << canvas_x << "\ty: " << canvas_y << "\tans: " << ans << endl;
	return ans;
}

string Polygon::draw(int canvas_x, int canvas_y) {
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
