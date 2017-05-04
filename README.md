# UnixEngine

A very basic View Engine for Unix.

Running
=======

To run UnixEngine simply copy the code below and add your code in the functions.

```c++

#include "../engine/engine.h"
using namespace std;

// Function called when command is written in the console
void command_written(string command);

// Function called before the next frame is rendered
void render_frame(Canvas *canvas);

int main()
{
    UnixEngine *engine = new UnixEngine();
    engine->set_canvas(120, 40);
    engine->start(render_frame, command_written);
    delete engine;
    return 0;
}
```

Draw
====

To launch Draw you need to compile the app and the engine and then launch it.

```
 > make draw
 > ./draw
```

In Draw you can paint views on a canvas by setting its various properties to create the exact view you want.

x

```
 >  View(x:10)
```

y

```
 >  View(y:10)
```

Width

```
 >  View(width:10)
```

Height

```
 >  View(height:10)
```

Background color

```
 >  View(background_color:10)
```

Style

```
 >  View(style:10)
```

Border width

```
 >  View(border_width:10)
```

Border Style

```
 >  View(border_style:10)
```

Border color

```
 >  View(border_color:10)
```

---

To create a view you can combine any these properties in any order you want.

```
 >  View(width: 20, height: 10, style: #)
```

![Screenshot 1](https://lh3.googleusercontent.com/2nab-kCRmqj8xODYcKRyTFxjg0SS49kUTPFvI_1PvAZc2Yba9brr5bp6Dspz4XafCHdGma2wQkmTzFoK8N0g4nlPABXJ5ZNNYV3YKoYuSv9ekSlH3R3n2CVFyEtpqbqk13Qh8A=w1112-h758-no "Screenshot 1")

```
 >  View(x: 10, y: 5, width: 5, height: 5, background_color: magenta, style: *)
```

![Screenshot 2](https://lh3.googleusercontent.com/eBFd-Drzxx9MgGctPV1wqOUF7ljqj9HhirT6VrBf72MCyY0twowELk_F4TYp3a_SiVtuUdAKrWEveYV9-jP9oV-hHgsR-EeVG5X0KrAOw60sSsi-SkVIBcK7W2SNnXvahyxOBQ=w1112-h760-no "Screenshot 2")

```
 >  View(x: 10, y: 5, width: 20, height: 10, border_width: 2, border_color: red, border_style: *)
```

![Screenshot 3](https://lh3.googleusercontent.com/NWVio7JQbX2i0ZQgWfatKfbQuV7rZ7aMU6BfjhE62sKp_dbXkLAtheSb_sng3xnp2Z4NnD7qnTCPxHOVu_EsCQ2Sr1ozfrYdizR9V5tlatJPwDTjoT4Yh6xEa4uGuLZv1GwoAw=w1112-h758-no "Screenshot 3")

```
 >  View(x: 20, y: 5, width: 25, height: 7, background_color: magenta, style: *, border_width: 1, border_color: red, border_style: #)
```

![Screenshot 4](https://lh3.googleusercontent.com/hBQq2otfmecKGnZI7jwLjQFueBZ0KtdGfwaF39afkcaAu-7FGRJhDITMa0MdTQ46fh59KSnNnOtAgrkZmzDT7GtNuwaTEvANYoaQK9jxtRXVDabvc7qtIsURepWxE5SWjH_wbg=w1112-h758-no "Screenshot 4")

You can also draw views on top of each other.

```
 >  View(x: 10, y: 5, width: 20, height: 10, border_width: 2, border_color: blue, border_style: *)
 >  View(x: 20, y: 5, width: 25, height: 7, background_color: magenta, style: *, border_width: 1, border_color: red, border_style: #)
```

![Screenshot 5](https://lh3.googleusercontent.com/FdjM324yYWDLx2HPo2UNTu5QR6JhclYhVWB6f5g9zbhxmIp5kCLyLzprbdN9ZZYMGkfb_fY59fBnnILEU-1pCUItEUzIYSEx21MOyPVg3GhfFx9hgg-djLC36y-GencTsa-FCA=w1112-h758-no "Screenshot 5")
