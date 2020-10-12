#include "include/taruga.hpp"

//! Draws a spiral. Do notice this'll probably take a while to finish.


int main()
{
    taruga::Turtle turtle;

    int size = 1;
    while (size <= 500)
    {
        turtle.forward(size++);
        turtle.turn_right(91);
    }

    turtle.act();

    return 0;
}
