#pragma once
#include <SFML/Graphics.hpp>

class Turtle {
public:
    Turtle(sf::RenderWindow& window);
    void move();
    void draw();
    sf::FloatRect getGlobalBounds() const;
    void resetPosition();

private:
    sf::RenderWindow& window; // 참조 형태로 SFML의 RenderWindow 객체를 저장. 거북이 객체가 창과 상호 작용하는 데 사용
    sf::Texture texture; // SFML의 Texture 클래스로, 거북이의 텍스처를 저장. 텍스처는 거북이의 외형을 정의하는 이미지를 나타냄
    sf::Sprite sprite; // SFML의 Sprite 클래스로, 텍스처를 가지고 있는 거북이 스프라이트를 나타냄. 스프라이트는 창에 그려지는 객체의 일반적인 형태
    sf::Vector2f velocity; // sf::Vector2f 형태로 거북이의 속도를 나타냄. 이 변수는 거북이가 이동할 때의 방향과 속도를 제어하는 데 사용됨
};
