#include "player.h"

Player::Player(Texture& texture, float x, float y) : GameObject(texture, x, y) {
}

void Player::update(const Vector2u& windowSize) {
    // Ű���� �Է� ó��
    float moveSpeed = 0.3f; // �̵� �ӵ��� �����Ϸ��� ���� ����
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-moveSpeed, 0.0f, windowSize); // ���� ����Ű
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(moveSpeed, 0.0f, windowSize); // ������ ����Ű
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(0.0f, -moveSpeed, windowSize); // ���� ����Ű
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0.0f, moveSpeed, windowSize); // �Ʒ��� ����Ű
    }
}
