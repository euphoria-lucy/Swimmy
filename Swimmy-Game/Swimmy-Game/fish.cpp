// fish.cpp
#include "fish.h"
#include <cstdlib>

Fish::Fish(sf::RenderWindow& window) : window(window) {
    if (texture.loadFromFile("fish.png")) {
        sprite.setTexture(texture);
        sprite.setScale(0.4f, 0.4f);
        resetPosition(); // 위치 초기화 함수 호출
    }
    // 초기 속도 설정
    velocity.x = static_cast<float>(rand() % 1 + 0.05f); // 랜덤한 가로 속도
    velocity.y = static_cast<float>(rand() % 1 + 0.05f); // 랜덤한 세로 속도
}

void Fish::resetPosition() {
    sprite.setPosition(static_cast<float>(rand() % static_cast<int>(window.getSize().x - sprite.getGlobalBounds().width)), // x 좌표 설정 (창의 너비에서 sprite의 전역 경계의 너비를 뺀 범위 내에서 랜덤한 값 생성)
        static_cast<float>(rand() % static_cast<int>(window.getSize().y - sprite.getGlobalBounds().height))); // y 좌표 설정 (창의 높이에서 sprite의 전역 경계의 높이를 뺀 범위 내에서 랜덤한 값 생성)
}

void Fish::move() {
    sprite.move(velocity);
    // 화면 경계에서 반사되도록 처리
    if (sprite.getPosition().x < 0 || sprite.getPosition().x > window.getSize().x - sprite.getGlobalBounds().width) { // 물고기의 sprite가 오른쪽 경계를 벗어나면
        velocity.x = -velocity.x; // 물고기의 x 방향 속도를 현재의 반대 방향으로 바꿔줌
    }
    if (sprite.getPosition().y < 0 || sprite.getPosition().y > window.getSize().y - sprite.getGlobalBounds().height) { // 물고기의 sprite가 왼쪽 경계를 벗어나면
        velocity.y = -velocity.y; // 물고기의 y방향 속도를 현재의 반대 방향으로 바꿈
    }
}

// 물고기의 sprite를 window에 그림
void Fish::draw() {
    window.draw(sprite);
}

// 물고기의 sprite의 전역 경계를 sf::FloatRect 객체로 반환
sf::FloatRect Fish::getGlobalBounds() const {
    return sprite.getGlobalBounds(); // sprite의 전역 경계를 나타내는 sf::FloatRect 반환 -> 스프라이트가 현재 위치, 크기, 회전 등의 변형을 고려한 전체적인 경계를 나타냄
}
