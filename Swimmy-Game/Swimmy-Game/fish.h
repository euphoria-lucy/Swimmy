#pragma once
#include <SFML/Graphics.hpp>

class Fish {
public:
    Fish(sf::RenderWindow& window);
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
