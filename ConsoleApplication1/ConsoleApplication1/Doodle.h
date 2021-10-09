#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Doodle
{
	int x = 0, y = 0;
	std::string name;
	sf::Texture texture;
	sf::Image image;
	sf::Sprite sprite;
public:

	Doodle(int x, int y) {
		this->texture.loadFromFile("doodle.png");
		this->sprite.setTexture(texture);
		this->x = x;
		this->y = y;
		this->sprite.setPosition(x, y);
	}

	Sprite getSprite() {
		return this->sprite;
	}

	void moveRight() {
		if (Keyboard::isKeyPressed(Keyboard::Right)) x += 4;
	}
	void moveLeft() {
		if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 4;
	}
	void Jump() {
		;

	}

};

