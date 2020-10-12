#include "include/taruga.hpp"

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

    turtle.turn_right(90);
    draw_spierpinski(turtle, 200, 3);
    turtle.act();

    return 0;
}
