#include "gameObject.h"

// ���� ��ü�� ��ġ�� �ؽ�ó(�̹���)�� ����
GameObject::GameObject(Texture& texture, float x, float y) {
    position = Vector2f(x, y);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

// ���� ��ü�� ȭ�鿡 �׸��� �Լ�
void GameObject::draw(RenderWindow& window) {
    window.draw(sprite);
}

// ���� ��ü�� ��ġ �̵��� �ϴ� �Լ�
/* void GameObject::move(float offsetX, float offsetY) {
    position.x += offsetX;
    position.y += offsetY;
    sprite.setPosition(position);
} */

void GameObject::move(float offsetX, float offsetY, const Vector2u& windowSize) {
    // �� ��ġ ���
    float newX = position.x + offsetX;
    float newY = position.y + offsetY;

    // ��ü�� �ٿ������ ���� �ʵ���
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


// ���� ��ü�� �ٸ� ���� ��ü ���� �浹 ���θ� �Ǵ� (�浹: ture ��ȯ)
bool GameObject::isColliding(const GameObject& other) {
    FloatRect thisBounds = sprite.getGlobalBounds();
    FloatRect otherBounds = other.sprite.getGlobalBounds();
    return thisBounds.intersects(otherBounds);
}