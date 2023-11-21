#include "turtle.h"
#include <cstdlib>

Turtle::Turtle(sf::RenderWindow& window) : window(window) {
    if (texture.loadFromFile("turtle.png")) {
        sprite.setTexture(texture);
        sprite.setScale(0.3f, 0.3f);
        resetPosition(); // ��ġ �ʱ�ȭ �Լ� ȣ��
    }
    // �ʱ� �ӵ� ����
    velocity.x = static_cast<float>(rand() % 1 + 0.05f); // ������ ���� �ӵ�
    velocity.y = static_cast<float>(rand() % 1 + 0.05f); // ������ ���� �ӵ�
}

/* void Turtle::resetPosition() {
    sprite.setPosition(static_cast<float>(rand() % static_cast<int>(window.getSize().x - sprite.getGlobalBounds().width)),
        static_cast<float>(rand() % static_cast<int>(window.getSize().y - sprite.getGlobalBounds().height)));
} */

void Turtle::resetPosition() {
    // ���⼭ 50�� ���ϴ� ������ ��Ÿ���ϴ�. �ʿ信 ���� �����ϼ���.
    float x = static_cast<float>(rand() % static_cast<int>(window.getSize().x - sprite.getGlobalBounds().width - 100));
    float y = static_cast<float>(rand() % static_cast<int>(window.getSize().y - sprite.getGlobalBounds().height - 100));

    sprite.setPosition(x, y);
}

void Turtle::move() {
    sprite.move(velocity);
    // ȭ�� ��迡�� �ݻ�ǵ��� ó��
    if (sprite.getPosition().x < 0 || sprite.getPosition().x > window.getSize().x - sprite.getGlobalBounds().width) {
        velocity.x = -velocity.x;
    }
    if (sprite.getPosition().y < 0 || sprite.getPosition().y > window.getSize().y - sprite.getGlobalBounds().height) {
        velocity.y = -velocity.y;
    }
}

void Turtle::draw() {
    window.draw(sprite);
}

sf::FloatRect Turtle::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}
