#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Platform
{
	int x = 0, y = 0;
	std::string name;
	sf::Texture texture;
	sf::Image image;
	sf::Sprite sprite;
public:

	Platform(int x, int y) {
		this->texture.loadFromFile("platform.png");
		this->sprite.setTexture(texture);
		this->x = x;
		this->y = y;
		this->sprite.setPosition(x, y);
	}

	Sprite getSprite() {
		return this->sprite;
	}

	void moveRight() {
		this->x++;
		this->y++;
	}
	void moveLeft() {
		this->x--;
		this->y++;
	}
	void Jump() {
		this->y;
	}

};