
#include "view.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

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

void append_property(string property, View *view)
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

void read_properties(string command, View *view, Canvas *canvas)
{
    size_t previous = 0;
    size_t found = command.find(",");
    while (found != string::npos)
    {
        append_property(command.substr(previous, found - previous), view);
        previous = found + 1;
        found = command.find(",", found + 1);
    }
    append_property(command.substr(previous), view);
    view->add_to(canvas);
    delete view;
}

View *create_object(string type)
{
    View *view;
    if (!type.compare("View"))
        view = new View();
    return view;
}

void read_command(string command, Canvas *canvas)
{
    View *view;
    string type;
    int i = 0;

    for (i = 0; i < command.length(); i++)
        if (command.at(i) == '(')
            break;
    if (i == command.length() || command.at(command.length() - 1) != ')')
        return ;

    type = command.substr(0, i);
    view = create_object(type);
    read_properties(command.substr(i + 1, command.length() - i - 2), view, canvas);
}

void add_command(string command, string *commands, int n)
{
    if (n < 10) {
        commands[n] = command;
    }
    else {
        for (int i = 0; i < 10; i++) {
            commands[i] = commands[i + 1];
        }
        commands[9] = command;
    }
}

void run_console(Canvas *canvas)
{
    int n = 0;
    string command = "";
    string *commands = new string[10];

    while (command.compare("exit"))
    {
        system("clear");
        canvas->draw();

        for (int i = 0; i < n; i++) {
            cout << " >  " << commands[i] << endl;
        }

        cout << " >  ";
        getline(cin, command);
        add_command(command, commands, n);
        if (n < 10)
            n++;
        
        read_command(command, canvas);
    }
}





// void frame(Canvas *canvas)
// {
//     View *view = new View();
//     view->x = 10;
//     view->y = 5;
//     view->width = 10;
//     view->height = 5;
//     view->set_background_color("green");
//     view->add_to(canvas);
//     delete view;
// }

// void run(Canvas *canvas, void (*f)(Canvas *))
// {
//     f(canvas);
// }

// void run_engine(Canvas *canvas, int fps)
// {
//     int n = 0;
//     string command = "";
//     string *commands = new string[10];

//     while (command.compare("exit"))
//     {
//         system("clear");
//         canvas->draw();

//         // for (int i = 0; i < n; i++) {
//         //     cout << " >  " << commands[i] << endl;
//         // }

//         // cout << " >  ";
//         // getline(cin, command);
//         // add_command(command, commands, n);
//         // if (n < 10)
//         //     n++;
        
//         run(canvas, frame);
//     }
// }








// Example using all properties
// View(x: 5, y: 2, width: 15, height: 10, style: #, background_color: blue, border_style: !, border_width: 2, border_color: red)

// Apps
//  Draw
//  Snake
//  Stocks

//  i.e. ./a.out snake

// Command
//  Canvas (edit the canvas size)
//  View
//  Path
//  etc

int main(int ac, char **av)
{
    // string option;

    // if (ac != 2) {
    //     cout << "Please specify if you want to run Snake or Console" << endl;
    //     cin >> option;
    //     cout << option;
    //     if (option.compare("snake") && option.compare("console"))
    //         return 0;
    // }

    Canvas *canvas = new Canvas();
    canvas->set_width(120);
    canvas->set_height(40);
    canvas->pixelate();

    run_console(canvas);
    // run_engine(canvas, 2);
    delete canvas;
    return 0;    
}

