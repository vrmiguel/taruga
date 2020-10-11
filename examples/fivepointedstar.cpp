#include "include/taruga.hpp"

//! Draws a spiral. Do notice this'll probably take a while to finish.


int main()
{
    taruga::Turtle turtle;

    turtle.turn_right(45);
    for(int i = 0; i < 5; i++)
    {
        turtle.forward(200);
        turtle.turn_left(144);
    }
    turtle.act();

    return 0;
}
