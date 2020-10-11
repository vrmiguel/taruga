#include "include/taruga.hpp"

//! Development file of Taruga. Will be deleted once this is no longer a WIP.

#include <string>
#include <cstdio>
#include <vector>

taruga::Turtle turtle;

int main()
{
    taruga::Turtle turtle;

    std::vector<sf::Color> colors = {sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Yellow};

    turtle.forward(70);
    turtle.turn_left(90);
    turtle.forward(70);
    turtle.turn_left(90);
    turtle.forward(70);
    turtle.turn_left(90);
    turtle.pen_up();
    turtle.forward(70);
    turtle.turn_left(90);

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
