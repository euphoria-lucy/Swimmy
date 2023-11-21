#pragma once

#include "gameObject.h"

class Fish : public GameObject {
public:
    // 생성자: 객체의 이미지 설정, 객체의 초기 x좌표 설정, 객체의 y좌표는 랜덤으로 지정
    Fish(Texture& texture, float initialX, float windowHeight);

    // 물고기 객체를 업데이트하는 함수
    void update();

    // 플레이어와 물고기의 충돌 여부를 판단하는 함수
    bool checkCollisionWithPlayer(const GameObject& player);

private:
    float moveSpeed;
};