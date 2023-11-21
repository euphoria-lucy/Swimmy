#include "fish.h"
#include <cstdlib>
#include <ctime>

Fish::Fish(Texture& texture, float initialX, float windowHeight)
    : GameObject(texture, initialX, static_cast<float>(rand() % static_cast<int>(windowHeight))) {
    moveSpeed = 0.03f; // 느린 이동 속도
}

void Fish::update() {
    // 물고기를 느린 속도로 왼쪽으로 이동
    move(-moveSpeed, 0.0f, sf::Vector2u(800, 600)); // 윈도우 크기에 맞게 수정
}

bool Fish::checkCollisionWithPlayer(const GameObject& player) {
    return isColliding(player);
}