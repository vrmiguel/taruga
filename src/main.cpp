#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "include/taruga.hpp"

//! Development file of Taruga. Will be deleted once this is no longer a WIP.

#include <string>
#include <cstdio>
#include <vector>

taruga::Turtle turtle;

void recursive_koch(int length, int depth)
{
    if (depth == 0)
    {
        turtle.forward(length); return;
    }
    recursive_koch(length, depth-1);
    turtle.turn_right(60);
    recursive_koch(length, depth-1);
    turtle.turn_left(120);
    recursive_koch(length, depth-1);
    turtle.turn_right(60);
    recursive_koch(length, depth-1);
}

int main()
{
    turtle.verbosity = taruga::Verbosity::VeryVerbose;
    recursive_koch(10, 2);

    //! Draw a square
//    turtle.turn_right(90);
//    turtle.forward(50);
//    turtle.turn_right(90);
//    turtle.forward(50);
//    turtle.turn_right(90);
//    turtle.forward(50);
//    turtle.turn_right(90);
//    turtle.forward(50);

    turtle.act();

    return 0;
}























//int main()
//{

//    sf::Image img;
//    img.loadFromFile("../ruga/turtle.png");

//    const uint8_t * imgptr = img.getPixelsPtr();

//    FILE * turtlebin = fopen("turtle.hpp", "w");
//    const size_t x = img.getSize().x;
//    const size_t y = img.getSize().y;
//    fprintf(turtlebin, "#ifndef __TURTLE_IMG_HPP\n");
//    fprintf(turtlebin, "#define __TURTLE_IMG_HPP\n\n");
//    fprintf(turtlebin, "const uint8_t turtle[%lu] = {", 4*x*y);
//    for(size_t i = 0; i < 4*x*y-1; i++)
//    {
//        fprintf(turtlebin, "%hhu, ", imgptr[i]);
//    }
//    fprintf(turtlebin, "%hhu};", imgptr[4*x*y-1]);
//    fprintf(turtlebin, "#endif\n");
//    fclose(turtlebin);

//    return 0;
//}
