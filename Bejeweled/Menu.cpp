#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//error loading the font
	}

	menu[0].setFont(font);
	menu[0].setCharacterSize(40);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("Mode Classique");
	menu[0].setPosition(250,150);

	menu[1].setFont(font);
	menu[1].setCharacterSize(40);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Mode Vitesse");
	menu[1].setPosition(275,250);

	menu[2].setFont(font);
	menu[2].setCharacterSize(40);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Rules");
	menu[2].setPosition(330,350);

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	sf::Texture t;
	t.loadFromFile("images/menu.png");
	sf::Sprite bg(t);
	window.draw(bg);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
	}
}

void Menu::MoveUp()
{	
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
	}
}
