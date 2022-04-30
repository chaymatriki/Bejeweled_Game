#pragma once
#include <SFML/Graphics.hpp>
#include "Cellule.h"
#include "Joueur.h"
#include "Partie.h"
#include "Mode1.h"
#include "Graphique.h"

class Graphique1 : public Graphique
{
public:
	Graphique1();
	void score_fct(Mode1 &game, Joueur &joueur, sf::Text &t_s, sf::Text &t_l);
	void affiche_fct(Partie &game, sf::RenderWindow &app, sf::Text &game_over, sf::Sprite &gem1, sf::Sprite &gem2,
		sf::Sprite &gem3, sf::Sprite &gem4, sf::Sprite &gem5, sf::Sprite &gem6, sf::Sprite &gem7,
		sf::Sprite &bg, sf::Sprite &sc, sf::Text &t_s, sf::Text &t_l, sf::Vector2i &decal,
		sf::Text &help0, sf::Text &help1, sf::Text &help2);
	void check_gameOver(Partie &game, sf::Text &game_over);
	void main_fct();
	
	~Graphique1();
};

