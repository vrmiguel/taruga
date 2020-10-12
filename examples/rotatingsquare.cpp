#include "include/taruga.hpp"

//! I'm not sure what this is called, but I adapted it from an article by Elliott Saslow


static inline void draw_square(taruga::Turtle& turtle)
{
    for(int i = 0; i < 4; i++)
    {
        turtle.forward(100);
        turtle.turn_left(90);
    }
}

int main()
{
    taruga::Turtle turtle;
    turtle.verbosity = taruga::Verbosity::VeryVerbose;

    for(int i = 1; i <= 360; i++)
    {
        draw_square(turtle);
        turtle.turn_left(i);
    }

    turtle.act();

    return 0;
}
