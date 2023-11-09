#include "gameObject.h"

// ���� ��ü�� ��ġ�� �ؽ�ó(�̹���)�� ����
GameObject::GameObject(Texture& texture, float x, float y) {
    position = Vector2f(x, y);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

// ���� ��ü�� ȭ�鿡 �׸��� ����
void GameObject::draw(RenderWindow& window) {
    window.draw(sprite);
}

// ���� ��ü�� �ٸ� ���� ��ü ���� �浹 ���θ� �Ǵ� (�浹: ture ��ȯ)
bool GameObject::isColliding(const GameObject& other) {
    FloatRect thisBounds = sprite.getGlobalBounds();
    FloatRect otherBounds = other.sprite.getGlobalBounds();
    return thisBounds.intersects(otherBounds);
}