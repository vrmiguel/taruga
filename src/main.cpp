#include "include/taruga.hpp"

//! Development file of Taruga. Will be deleted once this is no longer a WIP.

int main()
{
    taruga::Turtle turtle;

    //taruga::Turtle turtle;
    turtle.verbosity = taruga::Verbosity::VeryVerbose;

    turtle.pen_up();
    turtle.turn_right(90);
    turtle.forward(200);
    turtle.backwards(200);
    turtle.set_walking_speed(1.25);
    turtle.forward(200);
    turtle.backwards(200);
    turtle.turn_left(90);
    turtle.turn_right(180);
    turtle.turn_right(180);
    turtle.turn_right(90);
    turtle.set_rotation_speed(1.25);
    turtle.turn_right(180);
    turtle.turn_right(180);

    turtle.act();

    return 0;
}
