#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Doodle.h"
#include "Platform.h"
#include <random>


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
	sf::Text scoreText;
	sf::Text gameoverText;
    float x = 100, y = 100, h = 200;
	float dx, dy;
	float px = 0, py = 0;
	float score = 0;

public:
	MainWindow(int width, int height, std::string name) : sf::RenderWindow(sf::VideoMode(width, height), name) {
		if (!texture.loadFromFile("background.png"))
		{
			throw;
		}
		px = rand() % 400;
		py = rand() % 533;
		for (int i = 0; i < 10; i++) {
			this->platform = new Platform(px,py);
		}
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
			
			dy += 0.2;
			y += dy;
			if (y > 500) dy = -10;

			if (y < h)
				for (int i = 10; i < 10; i++)
				{
					y = h;
					py = py - dy;
					if (py > 533) {
						py = 0;
						px = rand() % 400;
					}
				}

			if (y == h && dy < (-1.62))
			{
				score += 1;
				scoreText.setString("Score: " + std::to_string(score));
			}

			for (int i = 0; i < 10; i++)
				if ((x + 50 > px) && (x + 20 < px + 68) && (y + 70 > py) && (y + 70 < py + 14) && (dy > 0)) dy = -10;

		this->player = new Doodle(x, y);

		if (y > 700)
		{
			gameoverText.setPosition(30, 200);
			scoreText.setPosition(150, 400);
		}
		window.draw(scoreText);
		window.display();


			this->clear(this->_bgColor);
			scoreText.setFont(font);
			scoreText.setCharacterSize(50);
			scoreText.setFillColor(sf::Color::Red);
			gameoverText.setFont(font);
			gameoverText.setString("Game Over!");
			gameoverText.setCharacterSize(80);
			gameoverText.setFillColor(sf::Color::Red);
			texture.setRepeated(true);
			texture.loadFromFile("background.png");
			sf::Sprite sprite(texture);
			this->draw(scoreText);
			window.draw(gameoverText);
			window.draw(scoreText);
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
