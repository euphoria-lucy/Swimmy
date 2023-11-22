#pragma once
#include <SFML/Graphics.hpp>

class Fish {
public:
    Fish(sf::RenderWindow& window); // Fish 클래스의 생성자, 창에 대한 참조를 받아와서 초기화, 물고기 텍스처 로드하고 초기 위치를 설정하는 작업 이루어짐
    void move(); // 물고기 움직이는 함수
    void draw(); // 물고기 화면에 그리는 함수
    sf::FloatRect getGlobalBounds() const; // 물고기 객체의 글로벌 경계를 반환하는 함수
    void resetPosition(); // 물고기 위치 재설정하는 함수

private:
    sf::RenderWindow& window; // 물고기 객체가 사용하는 SFML 창에 대한 참조
    sf::Texture texture; // 물고기의 텍스처를 저장하는 변수로, 물고기의 외형을 결정
    sf::Sprite sprite; // 물고기 객체의 스프라이트로, 텍스처를 가지고 있어서 화면에 물고기를 그릴 수 있음
    sf::Vector2f velocity; // 물고기의 이동 속도를 나타내는 2D 벡터 물고기가 얼마나 빨리 이동할지를 결정
};
