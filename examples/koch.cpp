#include "include/taruga.hpp"

void recursive_koch(taruga::Turtle& turtle, int length, int depth)
{
    if(depth == 0)
    {
        turtle.forward(length);
        return;
    }
    recursive_koch(turtle, length, depth-1);
    turtle.turn_right(60);
    recursive_koch(turtle, length, depth-1);
    turtle.turn_left(120);
    recursive_koch(turtle, length, depth-1);
    turtle.turn_right(60);
    recursive_koch(turtle, length, depth-1);
}

int main()
{
    taruga::Turtle turtle;

    turtle.pen_up();
    turtle.turn_right(90);
    turtle.backwards(850);
    turtle.turn_left(90);
    turtle.forward(190);
    turtle.turn_right(90);

    turtle.pen_down();
    recursive_koch(turtle, 5, 5);

    turtle.act();

    return 0;
}
