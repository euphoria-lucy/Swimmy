#include "fish.h"
#include <cstdlib>
#include <ctime>

Fish::Fish(Texture& texture, float initialX, float windowHeight)
    : GameObject(texture, initialX, static_cast<float>(rand() % static_cast<int>(windowHeight))) {
    moveSpeed = 0.03f; // ���� �̵� �ӵ�
}

void Fish::update() {
    // ����⸦ ���� �ӵ��� �������� �̵�
    move(-moveSpeed, 0.0f, sf::Vector2u(800, 600)); // ������ ũ�⿡ �°� ����
}

bool Fish::checkCollisionWithPlayer(const GameObject& player) {
    return isColliding(player);
}