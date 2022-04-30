#include "EntryPoint.h"
#include "Graphique1.h"
#include "Graphique2.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"


EntryPoint::EntryPoint()
{
}

void EntryPoint::main_fct()
{
	Graphique1 jeu;
	Graphique2 jeu2;
	sf::RenderWindow window(sf::VideoMode(750, 500), "Main Menu");
	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						jeu.main_fct();
						break;
					case 1:
						jeu2.main_fct();
						break;
					case 2:
						sf::Texture rule;
						rule.loadFromFile("images/rule.png");
						sf::Sprite rules(rule);
						sf::RenderWindow rules_w(sf::VideoMode(682, 426), "Rules");
						while (rules_w.isOpen())
						{
							sf::Event event;
							while (rules_w.pollEvent(event))
							{
								if (event.type == sf::Event::Closed)
									rules_w.close();
							}
							rules_w.draw(rules);
							rules_w.display();
						}

						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		menu.draw(window);
		window.display();
	}
}

EntryPoint::~EntryPoint()
{
}
