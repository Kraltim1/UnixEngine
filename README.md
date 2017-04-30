# UnixEngine

A very basic View Engine for Unix.

Running
=======

To run UnixEngine simply copy the code below and add your code in the functions.

```c++

#include "../engine/engine.h"

// Function called when command is written in the console
void command_written(string command);

// Function called before the next frame is rendered
void render_frame(Canvas *canvas);

int main()
{
    Engine *engine = new Engine();
    engine->set_canvas(120, 40);
    engine->start(render_frame, command_written);
    delete engine;
    return 0;
}
```
