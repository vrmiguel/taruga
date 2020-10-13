# Taruga Interpreter 

This is still in super early stages!
Will eventually be an interpreter for Taruga scripts.

For example, the colored square example,
```cpp
    std::vector<sf::Color> colors = {sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Yellow};

    for(auto color : colors)
    {
        turtle.set_line_color(color);
        turtle.forward(70);
        turtle.turn_left(90);
    }
```

becomes the following Taruga script:

```
    cc 255 0 0
    f 70.000
    l 90.000
    cc 0 0 255
    f 70.000
    l 90.000
    cc 0 255 0
    f 70.000
    l 90.000
    cc 255 255 0
    f 70.000
    l 90.000
```
