#include "include/taruga.hpp"

//! Development file of Taruga. Will be deleted once this is no longer a WIP.

int main()
{
    taruga::Turtle turtle;
    turtle.verbosity = taruga::Verbosity::VeryVerbose;

    turtle.forward(50);
    turtle.turn_right(90);
    turtle.forward(100);
    turtle.push_state();
    turtle.backwards(100);
    turtle.turn_left(90);
    turtle.backwards(50);
    turtle.pop_state();

    turtle.act();

    return 0;
}
