#include "gameObject.h"

// 생성자: 객체의 이미지 설정, 객체의 x좌표 설정, 객체의 y좌표 설정
GameObject::GameObject(Texture& texture, float x, float y) {
    position = Vector2f(x, y);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

// 게임 객체를 화면에 그리는 함수
void GameObject::draw(RenderWindow& window) {
    window.draw(sprite);
}

void GameObject::move(float offsetX, float offsetY, const Vector2u& windowSize) {
    // 새 위치 계산
    float newX = position.x + offsetX;
    float newY = position.y + offsetY;

    // 객체가 바운더리를 넘지 않도록
    if (newX < 0) {
        newX = 0;
    }
    else if (newX + sprite.getGlobalBounds().width > windowSize.x) {
        newX = windowSize.x - sprite.getGlobalBounds().width;
    }

    if (newY < 0) {
        newY = 0;
    }
    else if (newY + sprite.getGlobalBounds().height > windowSize.y) {
        newY = windowSize.y - sprite.getGlobalBounds().height;
    }

    position.x = newX;
    position.y = newY;

    sprite.setPosition(position);
}


// 게임 객체와 다른 게임 객체 간의 충돌 여부를 판단 (충돌: ture 반환)
bool GameObject::isColliding(const GameObject& other) {
    FloatRect thisBounds = sprite.getGlobalBounds();
    FloatRect otherBounds = other.sprite.getGlobalBounds();
    return thisBounds.intersects(otherBounds);
}