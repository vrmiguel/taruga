#include <iostream>

using namespace std;

#include "tarugainterpreter.hpp"

static inline void draw_regular_polygon(taruga::Turtle& turtle, const int num_sides, const int length, bool direction = false)
{
    const float angle = 360.0 / num_sides;
    if (direction) //! Direction ==  false := build the polygon upside down
    {
        for(int i = 0; i < num_sides; i++)
        {
            turtle.forward(length);
            turtle.turn_right(angle);
        }
    } else {
        for(int i = 0; i < num_sides; i++)
        {
            turtle.forward(length);
            turtle.turn_left(angle);
        }
    }
}

int main()
{
    taruga::Turtle turtle;
    draw_regular_polygon(turtle, 5, 30, false);
    turtle.pen_up();
    turtle.forward(200);
    turtle.turn_right(90);
    turtle.set_line_color(sf::Color::Red);
    turtle.pen_down();
    draw_regular_polygon(turtle, 8, 60, true);
    turtle.turn_left(90);
    turtle.turn_right(90);

    taruga::Interpreter::save_script(turtle, "script-test");

    turtle.act();
    return 0;
}
