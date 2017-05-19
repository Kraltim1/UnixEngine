#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse() {
	style = '#';
}

Ellipse::~Ellipse() {

}

bool Ellipse::checkFunction(int x,int y) {
	if (pow(x,2)/pow(width,2)+pow(y,2)/pow(height,2) <= 1) return 1;
	return 0;
}

void Ellipse::add_to(Canvas *canvas)
{
    int canvas_x;
    int canvas_y;
    stringstream ss;

    // For loop which cycles through all of the pixels in the canvas
    for (int i = 0; i < canvas->get_width() * canvas->get_height(); i++) {

        // Get the corresponding coordinates in the canvas
        canvas_x = i % canvas->get_width();
        canvas_y = i / canvas->get_width();

        // Only draw over pixels in the location of the view
        if (canvas_x >= x && canvas_x < x + width) {
            if (canvas_y >= y && canvas_y < y + height) {

                // Draw the pixels on the curve
                if (checkFunction(canvas_x,canvas_y)) {
                    ss << background_color << style << "\033[0m";
                }
                else {
                	ss << canvas->get_pixel(i);
                }

                // Draw the pixel on the canvas
                canvas->set_pixel(i, ss.str());
                ss.str("");
                ss.clear();
            }
        }
    }
}
