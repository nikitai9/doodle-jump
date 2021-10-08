#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Doodle.h"
#include "Platform.h"


using namespace sf;

class MainWindow : public sf::RenderWindow
{
	sf::Color _bgColor;
	std::string name;
	sf::Texture texture;
	sf::Image image;
	sf::RenderWindow window;
	sf::Font font;
	sf::Sprite sprite;
	Doodle *player;
	Platform *platform;

public:
	MainWindow(int width, int height, std::string name) : sf::RenderWindow(sf::VideoMode(width, height), name) {
		if (!texture.loadFromFile("background.png"))
		{
			throw;
		}
		this->player = new Doodle(200, 600);
		this->platform = new Platform(200,560);
		this->platform = new Platform(rand() % 400, rand() % 800);
	}
	void show() {
		while (this->isOpen())
		{
			sf::Event event;
			while (this->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					this->close();
				}
			}

			this->clear(this->_bgColor);
			texture.setRepeated(true);
			texture.loadFromFile("background.png");
			sf::Sprite sprite(texture);
			this->draw(sprite);
			this->draw(this->player->getSprite());
			this->display();
		}
	}

	void setBgColor(int r, int g, int b) {
		this->_bgColor.r = r;
		this->_bgColor.g = g;
		this->_bgColor.b = b;
	}
	void setBgColor(const sf::Color& _color) {
		this->_bgColor = sf::Color(_color);
	}

	~MainWindow() {}
};
