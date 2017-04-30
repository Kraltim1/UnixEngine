
#include "canvas.h"

Canvas::Canvas()
{
    style = '.';
    background_color = "\033[37m";
}

Canvas::~Canvas()
{
}

void Canvas::set_width(int m_width)
{
    width = m_width;
}

void Canvas::set_height(int m_height)
{
    height = m_height;
}

void Canvas::set_style(char m_style)
{
    style = m_style;
}

void Canvas::set_background_color(string color)
{
    if (!color.compare("black"))
        background_color = "\033[30m";
    else if (!color.compare("red"))
        background_color = "\033[31m";
    else if (!color.compare("green"))
        background_color = "\033[32m";
    else if (!color.compare("yellow"))
        background_color = "\033[33m";
    else if (!color.compare("blue"))
        background_color = "\033[34m";
    else if (!color.compare("magenta"))
        background_color = "\033[35m";
    else if (!color.compare("cyan"))
        background_color = "\033[36m";
    else if (!color.compare("white"))
        background_color = "\033[37m";
}

void Canvas::pixelate()
{
    stringstream ss;
    pixels = new string[width * height];

    for (int i = 0; i < width * height; i++) {
        ss << "\033[37m" << style << "\033[0m";
        pixels[i] = ss.str();
        ss.str("");
        ss.clear();
    }  
}

void Canvas::draw()
{
    for (int i = 0; i < width * height; i++) {
        cout << pixels[i];
        if (i % width == width - 1)
            cout << endl;
    }   
}
