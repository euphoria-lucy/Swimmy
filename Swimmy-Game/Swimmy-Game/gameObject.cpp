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
void GameObject::move(float offsetX, float offsetY) {
    position.x += offsetX;
    position.y += offsetY;
    sprite.setPosition(position);
}


// ���� ��ü�� �ٸ� ���� ��ü ���� �浹 ���θ� �Ǵ� (�浹: ture ��ȯ)
bool GameObject::isColliding(const GameObject& other) {
    FloatRect thisBounds = sprite.getGlobalBounds();
    FloatRect otherBounds = other.sprite.getGlobalBounds();
    return thisBounds.intersects(otherBounds);
}