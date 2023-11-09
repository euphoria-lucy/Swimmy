#include "gameObject.h"

// 게임 객체의 위치와 텍스처(이미지)를 설정
GameObject::GameObject(Texture& texture, float x, float y) {
    position = Vector2f(x, y);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

// 게임 객체를 화면에 그리는 함수
void GameObject::draw(RenderWindow& window) {
    window.draw(sprite);
}

// 게임 객체의 위치 이동을 하는 함수
void GameObject::move(float offsetX, float offsetY) {
    position.x += offsetX;
    position.y += offsetY;
    sprite.setPosition(position);
}


// 게임 객체와 다른 게임 객체 간의 충돌 여부를 판단 (충돌: ture 반환)
bool GameObject::isColliding(const GameObject& other) {
    FloatRect thisBounds = sprite.getGlobalBounds();
    FloatRect otherBounds = other.sprite.getGlobalBounds();
    return thisBounds.intersects(otherBounds);
}