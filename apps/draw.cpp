
#include "../engine/engine.h"

#include <iostream>
#include <algorithm>
#include <sys/ioctl.h>
#include <unistd.h>
#include <thread>
#include <time.h>

View *view;

string remove_spaces(string input)
{
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    return input;
}

int get_number(string property, int found)
{
    return stoi(remove_spaces(property.substr(found + 1, property.length())));
}

string get_string(string property, int found)
{
    return remove_spaces(property.substr(found + 1, property.length()));
}

char get_char(string property, int found)
{
    string str = remove_spaces(property.substr(found + 1, property.length()));

    if (str.length() == 1)
        return str.at(0);
    return 0;
}

void append_property(string property)
{
    string str;
    size_t found = property.find(":");

    if (found != string::npos) {
        str = remove_spaces(property.substr(0, found));
        if (!str.compare("x"))
            view->set_x(get_number(property, found));
        else if (!str.compare("y"))
            view->set_y(get_number(property, found));
        else if (!str.compare("width"))
            view->set_width(get_number(property, found));
        else if (!str.compare("height"))
            view->set_height(get_number(property, found));
        else if (!str.compare("style"))
            view->set_style(get_char(property, found));
        else if (!str.compare("background_color"))
            view->set_background_color(get_string(property, found));
        else if (!str.compare("border_color"))
            view->set_border_color(get_string(property, found));
        else if (!str.compare("border_style"))
            view->set_border_style(get_char(property, found));
        else if (!str.compare("border_width"))
            view->set_border_width(get_number(property, found));
        else {
            // error
        }
    }
}

void read_properties(string command)
{
    size_t previous = 0;
    size_t found = command.find(",");
    while (found != string::npos)
    {
        append_property(command.substr(previous, found - previous));
        previous = found + 1;
        found = command.find(",", found + 1);
    }
    append_property(command.substr(previous));
}

void create_object(string type)
{
    if (!type.compare("View"))
        view = new View();
}

// Function called when command is written in the console
void command_written(string command)
{
    string type;
    int i = 0;

    for (i = 0; i < command.length(); i++)
        if (command.at(i) == '(')
            break;
    if (i == command.length() || command.at(command.length() - 1) != ')')
        return ;

    type = command.substr(0, i);
    create_object(type);
    read_properties(command.substr(i + 1, command.length() - i - 2));
}

// Function called before the next frame is rendered
void render_frame(Canvas *canvas)
{
    if (view) {
        view->add_to(canvas);
        delete view;
        view = 0;
    }
}

int main()
{
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    UnixEngine *engine = new UnixEngine();
    engine->set_canvas(size.ws_col, size.ws_row - engine->getCommandHistory());
    engine->start(render_frame, command_written);
    delete engine;
    return 0;
}
