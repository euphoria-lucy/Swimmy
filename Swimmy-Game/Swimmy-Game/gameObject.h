#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject {
public:
    Vector2f position;
    Sprite sprite;

    GameObject(Texture& texture, float x, float y);
    void draw(RenderWindow& window);
    bool isColliding(const GameObject& other);
};