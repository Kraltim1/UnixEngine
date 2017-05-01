
#include "engine.h"

//******** Private Functions ********

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

//******** Engine Functions ********

UnixEngine::UnixEngine()
{
    canvas = new Canvas();
    console = false;
}

UnixEngine::~UnixEngine()
{
    system("clear");
    delete canvas;
}

void UnixEngine::start(void (*frame)(Canvas *), void (*parse)(string))
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
        
        if (command.compare("exit"))
            parse(command);
        frame(canvas);
    }
}

void UnixEngine::set_canvas(int width, int height)
{
    canvas->set_width(width);
    canvas->set_height(height);
    canvas->pixelate();
}
