#include "Btn.h"

Btn::Btn() {}

Btn::Btn(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
{
	text.setString(t);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	Button.setSize(size);
	Button.setFillColor(bgColor);
};

void Btn::setFont(sf::Font &font)
{
	text.setFont(font);
};

void Btn::setBackColor(sf::Color color)
{
	Button.setFillColor(color);
}

void Btn::setTextColor(sf::Color color)
{
	Button.setFillColor(color);
}

void Btn::setPosition(sf::Vector2f pos)
{
	Button.setPosition(pos);

	float xPos = (pos.x + Button.getLocalBounds().width / 7) - (text.getLocalBounds().width / 2);
	float yPos = (pos.y + Button.getLocalBounds().height / 8) - (text.getLocalBounds().height / 2);
	text.setPosition({ xPos, yPos });
}

void Btn::drawTo(sf::RenderWindow &window)
{
	window.draw(Button);
	window.draw(text);
}
bool Btn::isMouseOver(sf::RenderWindow &window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = Button.getPosition().x;
	float btnPosY = Button.getPosition().y;

	float btnxPosWidth = Button.getPosition().x + Button.getLocalBounds().width;
	float btnyPosHeight = Button.getPosition().y + Button.getLocalBounds().height;

	if (mouseX <btnxPosWidth && mouseX> btnPosX && mouseY <btnyPosHeight && mouseY>btnPosY)
	{
		return true;
	}
	return false;
}

Btn::~Btn()
{
}

