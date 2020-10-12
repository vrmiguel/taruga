# taruga

Taruga is a work in progress single-header turtle graphics library written in C++11.

<p align="center">
  <img src="gif/spiral.gif?raw=true" alt="Sublime's custom image"/>
</p>

## Examples

### Drawing a Spierpinski fractal

![Sierpinski](https://user-images.githubusercontent.com/36349314/95699821-e2950780-0c1b-11eb-8fa9-15b2e913ecc5.png)

With the simple Turtle directives, we can build complex fractals!

Full source code for this example can be found [here](examples/spiral.cpp).

### Drawing a spiral 

![Spiral](https://user-images.githubusercontent.com/36349314/95693453-c6d13780-0c02-11eb-9d4e-5d3b3467899e.png)

We can draw this spiral by simply moving forward and then turning to the right by slightly over 90°.

```cpp
    int size = 1;
    while (size <= 500)
    {
        turtle.forward(size++);
        turtle.turn_right(91);
    }
```

Full source code for this example  can be found [here](examples/spiral.cpp). 

### Using colors

![Colors](https://user-images.githubusercontent.com/36349314/95693689-fdf41880-0c03-11eb-800d-30867ebc2dd1.png)

We can change around the color of the lines drawn by using `Turtle::set_line_color`, to which you can supply either an RGB triplet (by individual values or in an array) or a [sf::Color](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php).

```cpp
    std::vector<sf::Color> colors = {sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Yellow};

    for(auto color : colors)
    {
        turtle.set_line_color(color);
        turtle.forward(70);
        turtle.turn_left(90);
    }
```

Full source code for this example can be found [here](examples/colored_square.cpp). 

### Lifting the pen up, drawing regular polygons

![Regular polygons](https://user-images.githubusercontent.com/36349314/95693724-3136a780-0c04-11eb-8797-9a25fc45ef2d.png)

We can set the turtle's pen up or down. This allows us to move the turtle without having to draw the line of its path.

Full source code for this example can be found [here](examples/regular_polygon.cpp). 

## Dependencies and how to build

The only dependencies are a C++11 conformant compiler and [SMFL](https://www.sfml-dev.org/index.php), a small multimedia API with an installed size of around 10MB.


Taruga has been built on SFML 2.5.1 and has also been tested on SFML 2.4.1. It may work on older versions of the library, but there are no guarantees.

On Ubuntu-based distributions, you can install SFML with:
```sudo apt install libsfml-dev```
On Fedora, with:
```dnf install SFML```

You can then build it ```g++ -O3 -std=c++11 your_program.cpp -lsfml-graphics -lsfml-window -lsfml-system```.

## Usage

Taruga exposes a single namespace, contained within a single header file.
The public methods that `taruga::Turtle` exposes are:

```cpp

    void set_window_title(const std::string& new_title);
    Turtle()                             : width(800),  height(600)  { init(); }
    Turtle(uint16_t _wth, uint16_t _hgt) : width(_wth), height(_hgt) { init(); }
    Turtle(const sf::Vector2u p)         : width(p.x),  height(p.y)  { init(); }
    void save_to_image(const char *);  //! Saves the current window view to an image with the given filename
    void set_line_color(sf::Color);    //! Sets the new color of the line the turtle will draw.
    void set_line_color(u8, u8, u8);   //! Sets the new color of the line the turtle will draw.
    void set_line_color(u8[3]);        //! Sets the new color of the line the turtle will draw.
    void pen_up();                     //! Sets the pen up so lines don't get drawn
    void pen_down();                   //! Sets the pen down so that the turtle draws a line wherever it walks
    void set_icon(Icon);               //! Allows to switch around between the two built-in icons: turtle or straight arrow.
    void set_icon(sf::Texture);        //! Allows for any image to be used as an icon. Do notice that Taruga won't scale the texture. If needed, use the Turtle::scale method.
    void scale(float, float);          //! Scales the turtle sprite
    void forward(int32_t units);       //! Walk forward the given amount of units.
    void backwards(int32_t units);     //! Walk backwards the given amount of units. The same as using forward() with a negative parameter.
    void turn_right(float ang);        //! Turns right by the specified amount of degrees.
    void turn_left(float ang);         //! Turns left by the specified amount of degrees.
    void draw_circle();                //! Draw a circle at the current position
    void act();                        //! Start moving the turtle. Will deplete the actions queue.
```

## Licensing

The code contained in this repo is [MIT](https://opensource.org/licenses/MIT)-licensed.
Turtle icon made by Freepik, available under the [Flaticon](https://www.flaticon.com/) license. 
SFML is [zlib/libpng](https://opensource.org/licenses/Zlib)-licensed

