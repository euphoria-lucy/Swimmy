#pragma once

#include "gameObject.h"

class Fish : public GameObject {
public:
    // ������: ��ü�� �̹��� ����, ��ü�� �ʱ� x��ǥ ����, ��ü�� y��ǥ�� �������� ����
    Fish(Texture& texture, float initialX, float windowHeight);

    // ����� ��ü�� ������Ʈ�ϴ� �Լ�
    void update();

    // �÷��̾�� ������� �浹 ���θ� �Ǵ��ϴ� �Լ�
    bool checkCollisionWithPlayer(const GameObject& player);

private:
    float moveSpeed;
};