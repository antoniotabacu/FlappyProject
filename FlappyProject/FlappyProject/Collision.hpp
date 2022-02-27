#pragma once

#include <SFML/Graphics.hpp>

namespace Tabacu {

	class Collision {
	public:
		Collision();

		bool CheckSpriteCollision(sf::Sprite sprite1,sf::Sprite sprite2);
		bool CheckSpriteCollision(sf::Sprite sprite1, float scal1, sf::Sprite sprite2, float scale2);
	};

}