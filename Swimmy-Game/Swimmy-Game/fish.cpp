// fish.cpp
#include "fish.h"
#include <cstdlib>

Fish::Fish(sf::RenderWindow& window) : window(window) {
    if (texture.loadFromFile("fish.png")) {
        sprite.setTexture(texture);
        sprite.setScale(0.4f, 0.4f);
        resetPosition(); // ��ġ �ʱ�ȭ �Լ� ȣ��
    }
    // �ʱ� �ӵ� ����
    velocity.x = static_cast<float>(rand() % 1 + 0.05f); // ������ ���� �ӵ�
    velocity.y = static_cast<float>(rand() % 1 + 0.05f); // ������ ���� �ӵ�
}

void Fish::resetPosition() {
    sprite.setPosition(static_cast<float>(rand() % static_cast<int>(window.getSize().x - sprite.getGlobalBounds().width)),
        static_cast<float>(rand() % static_cast<int>(window.getSize().y - sprite.getGlobalBounds().height)));
}

void Fish::move() {
    sprite.move(velocity);
    // ȭ�� ��迡�� �ݻ�ǵ��� ó��
    if (sprite.getPosition().x < 0 || sprite.getPosition().x > window.getSize().x - sprite.getGlobalBounds().width) {
        velocity.x = -velocity.x;
    }
    if (sprite.getPosition().y < 0 || sprite.getPosition().y > window.getSize().y - sprite.getGlobalBounds().height) {
        velocity.y = -velocity.y;
    }
}

void Fish::draw() {
    window.draw(sprite);
}

sf::FloatRect Fish::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}
