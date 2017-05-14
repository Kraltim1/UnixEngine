
#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Canvas
{
public:

    // Lifecycle
    Canvas();
    ~Canvas();

    // Functions
    void set_width(int m_width);
    void set_height(int m_height);
    void set_style(char m_style);
    void set_background_color(string color);
    void set_pixel(int pixel, string value);

    int get_width();
    int get_height();

    void pixelate();
    void draw();

protected:

    // Properties
    int width;
    int height;
    char style;
    string background_color;

private:

    // Properties
    string *pixels;
};

#endif
