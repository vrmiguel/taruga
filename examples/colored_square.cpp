#include "include/taruga.hpp"
#include <vector>

int main()
{
    taruga::Turtle turtle;

    std::vector<sf::Color> colors = {sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Yellow};

    for(auto color : colors)
    {
        turtle.set_line_color(color);
        turtle.forward(70);
        turtle.turn_left(90);
    }

    turtle.act();

    return 0;
}

