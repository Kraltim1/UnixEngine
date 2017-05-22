
#include "draw.h"

void Draw::draw(Canvas *canvas, View *view)
{
    string pixel;
    int canvas_x;
    int canvas_y;

    // For loop which cicles through all of the pixels in the canvas
    for (int i = 0; i < canvas->get_width() * canvas->get_height(); i++) {

        // Get the corresponding coordinates in the canvas
        canvas_x = i % canvas->get_width();
        canvas_y = i / canvas->get_width();

        // Select all pixels which match the area of the view on the canvas
        if (canvas_x >= view->get_x() && canvas_x < view->get_x() + view->get_width()) {
            if (canvas_y >= view->get_y() && canvas_y < view->get_y() + view->get_height()) {

                // Draw pixel on the canvas
                pixel = view->draw(canvas_x, canvas_y);
                canvas->set_pixel(i, pixel.compare("") ? pixel : canvas->get_pixel(i));
            }
        }
    }
}
