
#ifndef VIEW_H
#define VIEW_H

#include "canvas.h"
using namespace std;

/***********
*
*   Subclasses
*
*   - Text
*
*   - Table
*
*   - Path (x: 10, y: 10, path: [d4, l3, u9, r5], line_width: 2)
*
*   - Polygon
*
*       - Triangle (angle or direction property)
*
*       - Pentagon
*
***********/

class View : public Canvas
{
public:

    // Lifecycle
    View();
    ~View();

    // Functions
    void set_x(int m_x);
    void set_y(int m_y);
    void set_border_style(char m_border_style);
    void set_border_width(int m_border_width);
    void set_border_color(string color);
    void set_text(string m_text);

    virtual string draw(int canvas_x, int canvas_y);

    int get_x();
    int get_y();

protected:

    // Properties
    int x;
    int y;
    char border_style;
    int border_width;
    string border_color;
    string text;
};

#endif
