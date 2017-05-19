
#ifndef ENGINE_H
#define ENGINE_H

#include "view.h"
#include "Ellipse.h"

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class UnixEngine
{
public:
	
    // Lifecycle
    UnixEngine();
    ~UnixEngine();

    // Functions
    void start(void (*frame)(Canvas *), void (*parse)(string));
    void set_canvas(int width, int height);
	
	static const short commandHistory = 5;
	int getCommandHistory() {
		return commandHistory;
	}

private:

    // Functions
    void add_command(string command, int n);
    void render(string *command);

    // Properties
    int n;
    Canvas *canvas;
    string *commands;
};

#endif
