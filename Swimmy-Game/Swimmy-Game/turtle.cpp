#include "turtle.h"

Turtle::Turtle(Texture& texture, float x, float y) : GameObject(texture, x, y) {
    // Turtle 클래스의 생성자에서 GameObject의 생성자를 호출하여 초기화
    // 이동 및 충돌 메서드는 GameObject 클래스에서 상속받아 사용
}