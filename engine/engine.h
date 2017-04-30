
#ifndef ENGINE_H
#define ENGINE_H

#include "view.h"

#include <iostream>
#include <string>
using namespace std;

class Engine
{
public:

    // Lifecycle
    Engine();
    ~Engine();

    // Functions
    void start(void (*frame)(Canvas *), void (*parse)(string));
    void set_canvas(int width, int height);

    // Variables
    int fps;
    bool console;
    Canvas *canvas;
};

#endif