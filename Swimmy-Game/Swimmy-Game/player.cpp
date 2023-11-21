#include "player.h"

Player::Player(Texture& texture, float x, float y) : GameObject(texture, x, y) {
}

void Player::update(const Vector2u& windowSize) {
    // 키보드 입력 처리
    float moveSpeed = 0.3f; // 이동 속도를 조절하려면 값을 조정
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-moveSpeed, 0.0f, windowSize); // 왼쪽 방향키
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(moveSpeed, 0.0f, windowSize); // 오른쪽 방향키
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(0.0f, -moveSpeed, windowSize); // 위쪽 방향키
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0.0f, moveSpeed, windowSize); // 아래쪽 방향키
    }
}
