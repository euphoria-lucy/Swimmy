#pragma once

#include <SFML/Graphics.hpp>
#include "gameObject.h"

class Player : public GameObject {
public:
	Player(Texture& texture, float x, float y);
	void update(const Vector2u& windowSize);
};
