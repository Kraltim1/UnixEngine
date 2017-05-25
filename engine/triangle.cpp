#include "triangle.h"

Triangle::Triangle() {
	sides = 3;
}

Triangle::~Triangle() {
}






//
//string Triangle::draw(int canvas_x, int canvas_y)
//{
//    stringstream ss;
//
//    if (canvas_x >= x+width/2*(1+(canvas_y-y)/(-height)) && canvas_x <= x+width/2*(1-(canvas_y-y)/(-height))) {
//    	if (canvas_y >= y && canvas_y <= y+height) {
//    		cout << "x lower bound   = " << x+width/2*(1+(canvas_y-y)/(-height)) << endl;
//    		cout << "x greater bound = " << x+width/2*(1-(canvas_y-y)/(-height)) << endl;
//			// If not a border pixel, draw a body pixel
////			ss << background_color << style << "\033[0m";
//    	}
//    }
//
//    return ss.str();
//}


