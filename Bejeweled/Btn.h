#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Btn
{
public:
	Btn();

	Btn(std::string text, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor);

	void setFont(sf::Font &font);

	void setBackColor(sf::Color color);

	void setTextColor(sf::Color color);

	void setPosition(sf::Vector2f pos);

	void drawTo(sf::RenderWindow &window);

	bool isMouseOver(sf::RenderWindow &window);

	~Btn();

private:
	sf::RectangleShape Button;
	sf::Text text;
};

