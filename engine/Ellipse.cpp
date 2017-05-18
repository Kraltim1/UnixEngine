#include "Ellipse.h"

Ellipse::Ellipse() {
	// TODO Auto-generated constructor stub
	a = 0;
	b = 0;
}

Ellipse::~Ellipse() {
	// TODO Auto-generated destructor stub
}

bool Ellipse::checkFunction(int x,int y,int a,int b) {
	if (x/a+y/b == 1) return 1;
	return 0;
}

void Ellipse::setAValue(int m_a) {
	a = m_a;
}

void Ellipse::setBValue(int m_b) {
	b = m_b;
}

void Ellipse::plot(Canvas *canvas)
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
                if (checkFunction(canvas_x,canvas_y,a,b)) {
                    ss << background_color << style << "\033[0m";
                }

                // Draw the pixel on the canvas
                canvas->set_pixel(i, ss.str());
                ss.str("");
                ss.clear();
            }
        }
    }
}
