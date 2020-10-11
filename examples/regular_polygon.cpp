#include "include/taruga.hpp"

//! Development file of Taruga. Will be deleted once this is no longer a WIP.

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

    draw_regular_polygon(turtle, 6, 50, true);
    turtle.turn_left(90);
    turtle.pen_up();
    turtle.forward(80);
    turtle.turn_right(90);
    turtle.pen_down();
    draw_regular_polygon(turtle, 8, 10);
    turtle.pen_up();
    turtle.forward(200);
    turtle.pen_down();
    draw_regular_polygon(turtle, 3, 50, false);

    turtle.act();

    return 0;
}

