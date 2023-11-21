#pragma once
#include <SFML/Graphics.hpp>

class Turtle {
public:
    Turtle(sf::RenderWindow& window);
    void move();
    void draw();
    sf::FloatRect getGlobalBounds() const;
    void resetPosition();

private:
    sf::RenderWindow& window;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
};
