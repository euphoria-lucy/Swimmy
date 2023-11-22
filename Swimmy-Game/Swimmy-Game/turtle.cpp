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
    float x = static_cast<float>(rand() % static_cast<int>(window.getSize().x - sprite.getGlobalBounds().width - 100)); // 가로 크기에서 sprite의 전역 경계의 너비를 뺀 값에 대한 랜덤한 x좌표 생성
    float y = static_cast<float>(rand() % static_cast<int>(window.getSize().y - sprite.getGlobalBounds().height - 100)); // 세로 크기에서 sprite의 전역 경계의 높이를 뺀 값에 대한 랜덤한 y좌표 생성

    sprite.setPosition(x, y);
}

void Turtle::move() {
    sprite.move(velocity);
    // 화면 경계에서 반사되도록 처리
    if (sprite.getPosition().x < 0 || sprite.getPosition().x > window.getSize().x - sprite.getGlobalBounds().width) { // 거북이의 sprite가 화면의 오른쪽 또는 왼쪽 경계 벗어나면
        velocity.x = -velocity.x; // x축 방향의 속도를 반대로 변경
    }
    if (sprite.getPosition().y < 0 || sprite.getPosition().y > window.getSize().y - sprite.getGlobalBounds().height) { // 거북이의 sprite가 화면의 위쪽 또는 아래쪽 경계를 벗어나면
        velocity.y = -velocity.y; // y축 방향의 속도를 반대로 변경 
    }
}

// 거북이를 게임 창에 표시
void Turtle::draw() {
    window.draw(sprite);
}

// Turtle 객체의 sprite의 전역 경계를 나타내는 sf:FloatRect 객체 반환
// 객체의 충돌 감지 목적으로 사용
sf::FloatRect Turtle::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}