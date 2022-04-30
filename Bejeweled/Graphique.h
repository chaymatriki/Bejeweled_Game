#pragma once
#include "Btn.h"
class Graphique
{
public:
	Graphique();
	void load_textures_fct(sf::Texture &t0, sf::Texture &t1, sf::Texture &t2, sf::Texture &t3, sf::Texture &t4, sf::Texture &t5, sf::Texture &t6, sf::Texture &t7, sf::Texture &sc);
	void click_fct(int click, int &x1, int &y1, int &x2, int &y2, sf::Vector2i pos, Partie &game);
	void check(Partie &game, int &x1, int &y1, int &x2, int &y2);
	virtual void affiche_fct(Partie &game, sf::RenderWindow &app, sf::Sprite &gem1
		, sf::Sprite &gem2, sf::Sprite &gem3, sf::Sprite &gem4, sf::Sprite &gem5,
		sf::Sprite &gem6, sf::Sprite &gem7,sf::Sprite &bg, sf::Sprite &sc, sf::Text &t_s,
		sf::Vector2i &decal, sf::Text &help0, sf::Text &help1, sf::Text &help2);
	
	~Graphique();
};

