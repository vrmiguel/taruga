#include "include/taruga.hpp"

//! Development file of Taruga. Will be deleted once this is no longer a WIP.

//! Draws a Sierpinski fractal
void draw_spierpinski(taruga::Turtle& t, const int length, int depth)
{
    if(depth == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            t.forward(length);
            t.turn_left(120);
        }
        return;
    }
    draw_spierpinski(t, length/2, depth-1);
    t.forward(length/2);
    draw_spierpinski(t, length/2, depth-1);
    t.backwards(length/2);
    t.turn_left(60);
    t.forward(length/2);
    t.turn_right(60);
    draw_spierpinski(t, length/2, depth-1);
    t.turn_left(60);
    t.backwards(length/2);
    t.turn_right(60);
}


int main()
{
    taruga::Turtle turtle;
    turtle.verbosity = taruga::Verbosity::VeryVerbose;

//    for(int i = 0; i < 36; i++)
//    {
//        turtle.turn_right(10*i);
//        turtle.forward(50);
//        turtle.backwards(50);
//        turtle.turn_left(10*i);
//    }


    turtle.turn_right(90);
    draw_spierpinski(turtle, 200, 3);

    turtle.save_to_image("screenshot.png");
    turtle.act();

    return 0;
}
