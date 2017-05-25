
#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "view.h"

#include <cmath>

class Ellipse: public View
{
public:

    // Lifeycle
	Ellipse();
    ~Ellipse();
    
    // Functions
    string draw(int canvas_x, int canvas_y);
};

#endif
