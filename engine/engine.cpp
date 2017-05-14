
#include "engine.h"
using namespace std;

//******** Engine Functions ********

UnixEngine::UnixEngine()
{
    // Alloc memory on startup
    canvas = new Canvas();
    commands = new string[10];
    n = 0;
}

UnixEngine::~UnixEngine()
{
    // Clear the terminal when the engine is deallocated
    system("clear");
    delete canvas;
}

void UnixEngine::start(void (*frame)(Canvas *), void (*parse)(string))
{
    string command = "";

    // Continue loop in the command entered is not "exit"
    while (command.compare("exit"))
    {
        // Call the render function to store the command in the variable
        render(&command);

        // Check the command and if not "exit", call the parse function in the app
        if (command.compare("exit"))
            parse(command);
        
        // Call the frame function from the app to update the next canvas rendered
        frame(canvas);
    }
}

void UnixEngine::set_canvas(int width, int height)
{
    // Set dimensions of the canvas
    canvas->set_width(width);
    canvas->set_height(height);

    // Set pixel data of the canvas
    canvas->pixelate();
}

//******** Private Functions ********

void UnixEngine::add_command(string command, int n)
{
    // Add command to list if less than 10
    if (n < 10) {
        commands[n] = command;
    }
    else {
        // Bring commands forward in the list
        for (int i = 0; i < 9; i++) {
            commands[i] = commands[i + 1];
        }

        // Add command to the of the list
        commands[9] = command;
    }
}

void UnixEngine::render(string *command)
{
    // Clear the terminal window before the new render and then draw the canvas
    system("clear");
    canvas->draw();

    // Draw the console with the previous commands
    for (int i = 0; i < n; i++) {
        cout << " >  " << commands[i] << endl;
    }
    cout << " >  ";

    // Wait for commmand
    getline(cin, *command);

    // Add command to the list
    add_command(*command, n);
    if (n < 10)
        n++;
}
