#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::RenderWindow& window);
    void move();
    void draw();

    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;

    void increaseScore();
    void decreaseScore();
    int getScore();

private:
    sf::RenderWindow& window;
    sf::Texture texture;
    sf::Sprite sprite;
    int score;
};
