#pragma once
#include <SFML/Graphics.hpp>
#include "Cellule.h"
#include "Joueur.h"
#include "Partie.h"
#include "Mode2.h"
#include "Graphique.h"

class Graphique2 : public Graphique
{
private:
	int b_score;
public:
	Graphique2();
	void score_fct(Mode2 &game, Joueur &joueur, sf::Text &t_s);
	void affiche_fct(Partie &game, sf::RenderWindow &app, sf::Sprite &gem1, sf::Sprite &gem2, sf::Sprite &gem3,
		sf::Sprite &gem4, sf::Sprite &gem5, sf::Sprite &gem6, sf::Sprite &gem7, sf::Sprite &bg, sf::Sprite &sc,
		sf::Text &t_s, sf::Vector2i &decal, sf::Sprite &sclock, sf::Text &chrono, sf::Text &game_over, sf::Text &best_score,
		sf::Text &bs_t, sf::Text &help0, sf::Text &help1, sf::Text &help2);
	void check_gameOver(Partie &game);
	void main_fct();
	~Graphique2();
};

