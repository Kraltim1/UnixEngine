
#include "view.h"

View::View() : Canvas()
{
    // Set defaults on alloc
    x = 0;
    y = 0;
    border_width = 0;
    border_color = "\033[37m";
    border_style = '*';
}

View::~View()
{
}

void View::set_x(int m_x)
{
    x = m_x;
}

void View::set_y(int m_y)
{
    y = m_y;
}

void View::set_position(int m_x, int m_y)
{
    x = m_x;
    y = m_y;
}

void View::set_border_style(char m_border_style)
{
    border_style = m_border_style;
}

void View::set_border_width(int m_border_width)
{
    border_width = m_border_width;
}

void View::set_border_color(string color)
{
    // Set proper color based on function argument
    if (!color.compare("black"))
        border_color = "\033[30m";
    else if (!color.compare("red"))
        border_color = "\033[31m";
    else if (!color.compare("green"))
        border_color = "\033[32m";
    else if (!color.compare("yellow"))
        border_color = "\033[33m";
    else if (!color.compare("blue"))
        border_color = "\033[34m";
    else if (!color.compare("magenta"))
        border_color = "\033[35m";
    else if (!color.compare("cyan"))
        border_color = "\033[36m";
    else if (!color.compare("white"))
        border_color = "\033[37m";
}

void View::add_to(Canvas *canvas)
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

                // Filter out the borders and draw the corresponding pixels
                if (canvas_x - x < border_width || x + width - canvas_x <= border_width) {
                    ss << border_color << border_style << "\033[0m";
                }
                else if (canvas_y - y < border_width || y + height - canvas_y <= border_width)
                    ss << border_color << border_style << "\033[0m";
                else {
                    // If not a border pixel, draw a body pixel
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
