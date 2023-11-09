#pragma once

#include <SFML/Graphics.hpp>
#include "gameObject.h"

class Fish : public GameObject {
public:
	Fish(Texture& texture, float x, float y);
};