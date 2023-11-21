// player.cpp
#include "player.h"

using namespace std;

Player::Player(sf::RenderWindow& window) : window(window), score(0) {
    if (texture.loadFromFile("player.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
        sprite.setScale(0.3f, 0.2f);
    }
}

void Player::move() {
    float speed = 0.3f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0) {
        sprite.move(0, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < window.getSize().y - sprite.getGlobalBounds().height) {
        sprite.move(0, speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) {
        sprite.move(-speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < window.getSize().x - sprite.getGlobalBounds().width) {
        sprite.move(speed, 0);
    }
}

void Player::draw() {
    window.draw(sprite);
}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect Player::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

void Player::increaseScore() {
    score++;
    sf::err() << "점수: " << score << std::endl;
}

void Player::decreaseScore() {
    score--;
    sf::err() << "점수: " << score << std::endl;
}

int Player::getScore() {
    return score;
}
