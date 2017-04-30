
#include "view.h"

View::View() : Canvas()
{
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

    for (int i = 0; i < canvas->width * canvas->height; i++) {
        canvas_x = i % canvas->width;
        canvas_y = i / canvas->width;

        if (canvas_x >= x && canvas_x < x + width) {
            if (canvas_y >= y && canvas_y < y + height) {
                if (canvas_x - x < border_width || x + width - canvas_x <= border_width)
                    ss << border_color << border_style << "\033[0m";
                else if (canvas_y - y < border_width || y + height - canvas_y <= border_width)
                    ss << border_color << border_style << "\033[0m";
                else
                    ss << background_color << style << "\033[0m";

                canvas->pixels[i] = ss.str();
                ss.str("");
                ss.clear();
            }
        }
    }
}
