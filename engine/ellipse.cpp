
#include "ellipse.h"

Ellipse::Ellipse() : View() {}

Ellipse::~Ellipse() {}

string Ellipse::draw(int canvas_x, int canvas_y)
{
    stringstream ss;

    // Establish ellipse center
    float x0 = x + width / 2;
    float y0 = y + height / 2;

    // Ellipse variables
    float border = height > width ? height : width;
    float max = pow(1 - (border_width * 2) / border, 2);
    float distance = pow(canvas_x - x0, 2) / pow(width / 2, 2) + pow(canvas_y - y0, 2) / pow(height / 2, 2);

    // Check if point is within the bounds of the ellipse
    if (distance <= max)
        ss << background_color << style << "\033[0m";
    else if (distance <= 1)
        ss << border_color << border_style << "\033[0m";

    return ss.str();
}
