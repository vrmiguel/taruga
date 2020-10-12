#include "include/taruga.hpp"

void tree(taruga::Turtle& turtle, float length, float n)
{
    if (length < (length/n))
    {
        return;
    }
    turtle.forward(length);
    turtle.turn_left(45);
    tree(turtle, length * 0.5,length/n);
    turtle.turn_left(20);
    tree(turtle, length * 0.5,length/n);
    turtle.turn_right(75);
    tree(turtle, length * 0.5,length/n);
    turtle.turn_right(20);
    tree(turtle, length * 0.5,length/n);
    turtle.turn_left(30);
    turtle.backwards(length);
}

int main()
{
    taruga::Turtle turtle;

    turtle.turn_right(90);
    tree(turtle, 200, 2);

    turtle.act();

    return 0;
}
