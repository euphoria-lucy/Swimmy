// player.cpp
#include "player.h"

using namespace std;

// Player 클래스 생성자 정의
Player::Player(sf::RenderWindow& window) : window(window), score(0) {
    if (texture.loadFromFile("player.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
        sprite.setScale(0.3f, 0.2f);
    }
}

void Player::move() {
    float speed = 0.3f; // 플레이어가 한 번의 이동에 얼마나 움직일지 결정

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0) { // 위쪽 화살표 키 눌림, 플레이어가 화면 위쪽 경계 벗어나지 않았으면
        sprite.move(0, -speed); // 위쪽으로 speed만큼 이동
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < window.getSize().y - sprite.getGlobalBounds().height) { // 아래쪽 화살표 키 눌림, 플레이어가 화면 아래쪽 경계 벗어나지 않았으면
        sprite.move(0, speed); // 아래쪽으로 speed만큼 이동
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) { // 왼쪽 화살표 키 눌림, 플레이어가 화면 왼쪽 경계를 벗어나지 않았으면
        sprite.move(-speed, 0); // 왼쪽으로 speed만큼 이동
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < window.getSize().x - sprite.getGlobalBounds().width) { // 오른쪽 화살표 키 눌림, 플레이어가 화면 오른쪽 경계를 벗어나지 않았다면
        sprite.move(speed, 0); // 오른쪽으로 speed만큼 이동
    }
}

// 플레이어 객체 화면에 그림
void Player::draw() {
    window.draw(sprite); // 현재 위치 및 상태에 맞게 설정된 스프라이트를 화면에 그림
}

// 현재 위치를 sf:Vector2f 형태로 반환
// 플레이어 스프라이트의 현재 위치 가져오는 함수
sf::Vector2f Player::getPosition() const { // x좌표, y좌표를 가진 'sf::Vector2f' 형태로 반환
    // const로 선언되어 있으므로 이 함수를 호출하는 동안 Player 객체 수정되지 않음을 보장
    return sprite.getPosition();
}

// Player 클래스의 객체가 차지하는 전역 경계 상자(sf::FloatRect)를 반환
sf::FloatRect Player::getGlobalBounds() const { // 해당 스프라이트가 차지하는 영역의 전역 경계 상자 반환 -> 플레이어 스프라이트의 현재 위치와 크기를 나타내는 sf::FloatRect 객체가 반환
    // const로 선언되어 있으므로 이 함수를 호출하는 동안 Player 객체 수정되지 않음을 보장
    return sprite.getGlobalBounds();
}

// 스코어 증가
void Player::increaseScore() {
    score++;
    sf::err() << "스코어 : " << score << std::endl; // sf::err()를 사용하여 현재 스코어 값을 표준 에러 출력에 출력
}

// 스코어 감소
void Player::decreaseScore() {
    score--;
    sf::err() << "스코어 : " << score << std::endl; // sf::err()를 사용하여 현재 스코어 값을 표준 에러 출력에 출력
}

// 스코어 초기화
void Player::resetScore() {
    score = 0;
    sf::err() << "스코어 초기화" << std::endl; // sf::err()를 사용하여 스코어 초기화 출력
}

// 스코어 반환
int Player::getScore() {
    return score;
}
