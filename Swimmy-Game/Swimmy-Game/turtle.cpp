#include "turtle.h"
#include <cstdlib>

Turtle::Turtle(sf::RenderWindow& window) : window(window) {
    if (texture.loadFromFile("turtle.png")) {
        sprite.setTexture(texture);
        sprite.setScale(0.3f, 0.3f);
        resetPosition(); // 위치 초기화 함수 호출
    }
    // 초기 속도 설정
    velocity.x = static_cast<float>(rand() % 1 + 0.05f); // 랜덤한 가로 속도
    velocity.y = static_cast<float>(rand() % 1 + 0.05f); // 랜덤한 세로 속도
}

/* void Turtle::resetPosition() {
    sprite.setPosition(static_cast<float>(rand() % static_cast<int>(window.getSize().x - sprite.getGlobalBounds().width)),
        static_cast<float>(rand() % static_cast<int>(window.getSize().y - sprite.getGlobalBounds().height)));
} */

void Turtle::resetPosition() {
    // 여기서 50은 원하는 간격을 나타냅니다. 필요에 따라 조절하세요.
    float x = static_cast<float>(rand() % static_cast<int>(window.getSize().x - sprite.getGlobalBounds().width - 100));
    float y = static_cast<float>(rand() % static_cast<int>(window.getSize().y - sprite.getGlobalBounds().height - 100));

    sprite.setPosition(x, y);
}

void Turtle::move() {
    sprite.move(velocity);
    // 화면 경계에서 반사되도록 처리
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
