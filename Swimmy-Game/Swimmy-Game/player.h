#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::RenderWindow& window); // 생성자, 플레이어 객체 초기화 -> 창에 대한 참조 받아오고, 텍스처 로드하고 초기위치 설정
    void move();    // 플레이어 이동시키는 함수
    void draw();    // 플레이어 화면에 그리는 함수

    sf::Vector2f getPosition() const;       // 플레이어의 현재 위치 반환하는 함수
    sf::FloatRect getGlobalBounds() const;  // 플레이어의 스프라이트의 전역 경계 상자 반환 함수

    void increaseScore();   // 플레이어 점수 증가 함수
    void decreaseScore();   // 플레이어 점수 감소 함수
    void resetScore();      // 플레이어 점수 초기화 함수
    int getScore();         // 플레이어 현재 점수 반환하는 함수

private:
    sf::RenderWindow& window; // 참조 형태로 SFML의 RenderWindow 객체를 저장
    sf::Texture texture; // SFML의 Texture 클래스로 텍스처를 저장 텍스처는 일반적으로 객체의 외양을 정의하는 이미지를 나타냄
    sf::Sprite sprite;   // SFML의 Sprite 클래스로, 텍스처를 가지고 있는 스프라이트 스프라이트는 창에 그려지는 객체의 일반적인 형태
    int score; // 정수형으로 플레이어의 현재 점수 저장
};
