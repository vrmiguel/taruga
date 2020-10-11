#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "include/taruga.hpp"

// Icon: https://www.flaticon.com/authors/freepik, Flaticon licensed

#include <string>
#include <cstdio>
#include <vector>

int main()
{
    taruga::Turtle turtle;
    turtle.verbosity = taruga::Verbosity::VeryVerbose;

    //! Draw a square
//    turtle.turn_right(90);
//    turtle.forward(50);
//    turtle.turn_right(90);
//    turtle.forward(50);
//    turtle.turn_right(90);
//    turtle.forward(50);
//    turtle.turn_right(90);
//    turtle.forward(50);

    int size = 1;
    while (size <= 500)
    {
        turtle.forward(size);
        turtle.turn_right(91);
        size++;
    }

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
