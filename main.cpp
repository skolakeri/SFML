#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{
    /*
     * Initialization Code
     */
    // sf:: sfml namespace
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(35);
    sf::CircleShape shape2(25);
    shape2.setFillColor(sf::Color::Blue);
    shape.setFillColor(sf::Color::Green);
    shape2.setPosition(sf::Vector2f(50,120));

    float circleX = 0, circleY = 0;
    while (window.isOpen())
    {
        // Event System:
        /*
         * Jobs to manipulate window. Works with the operating system
         */
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        circleX += 0.01f;
        circleY += 0.005f;
        /*
         * Get mouse position
         */
        auto mousePosition = sf::Mouse::getPosition(window);
        //cout << "X:" << mousePosition.x << "Y: " << mousePosition.y << endl;
        // Draw Stuff
        // Three step process,
        // First clear everything on screen
        // Default color black
        window.clear();
        // Redraw shape
        // Takes in object of type drawable, uses polymorphism
        //shape2.setPosition(sf::Vector2f(mousePosition.x,mousePosition.y));
        shape2.setPosition(sf::Vector2f(circleX,circleY));
        auto position = shape2.getPosition();
        cout << "x: " << position.x << "y " << position.y << endl;
        window.draw(shape2);
        window.draw(shape);

        window.display();

        /*
         * Will do this many many times, "think" etch a sketech
         * So, call clear and display onece, and all draws will be in the middle
         */
    }

    return 0;
}
