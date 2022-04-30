#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <time.h>
#include "Cellule.h"
#include "Joueur.h"
#include "Partie.h"
#include "Mode1.h"
#include "Graphique.h"

using namespace sf;

Graphique::Graphique()
{
}

template <typename T>
std::string toString(T arg)
{
	std::stringstream ss;
	ss << arg;
	return ss.str();
}


void Graphique::load_textures_fct(Texture &t0, Texture &t1, Texture &t2, Texture &t3, Texture &t4, Texture &t5, Texture &t6, Texture &t7, Texture &sc)
{
	t0.loadFromFile("images/background4.png");
	t1.loadFromFile("images/1.png");
	t2.loadFromFile("images/2.png");
	t3.loadFromFile("images/3.png");
	t4.loadFromFile("images/4.png");
	t5.loadFromFile("images/5.png");
	t6.loadFromFile("images/6.png");
	t7.loadFromFile("images/7.png");
	sc.loadFromFile("images/score.png");
}

void Graphique::click_fct(int click, int &x1, int &y1, int &x2, int &y2, Vector2i pos, Partie &game)
{
	if (click == 1)
	{
		x1 = pos.x / taille + 1; //ligne
		y1 = pos.y / taille + 1; //col
	}
	if (click == 2)
	{
		x2 = pos.x / taille + 1;
		y2 = pos.y / taille + 1;

		if (abs(x2 - x1) + abs(y2 - y1) == 1) //si le switch est possible ou pas
		{
			game.echanger(game.grille[y1][x1], game.grille[y2][x2]);
			game.set_isSwitch(true);
			game.set_click(0);
		}
		else game.set_click(1);
	}
}

void Graphique::check(Partie &game, int &x1, int &y1, int &x2, int &y2)
{
	int curr_score = 0;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
		{
			curr_score += game.grille[i][j].get_match();
		}
	if (game.get_isSwitch() && !game.get_isMoving())
	{
		if (!curr_score)
			game.echanger(game.grille[y1][x1], game.grille[y2][x2]);
		game.set_isSwitch(false);
	}
}



void Graphique::affiche_fct(Partie &game, RenderWindow &app, Sprite &gem1, Sprite &gem2, Sprite &gem3, Sprite &gem4, Sprite &gem5, Sprite &gem6, Sprite &gem7, Sprite &bg, Sprite &sc, Text &t_s, Vector2i &decal, Text &help0, Text &help1, Text &help2)
{
	app.draw(bg);
	app.draw(sc);
	app.draw(t_s);
	app.draw(help0);
	app.draw(help1);
	app.draw(help2);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			Cellule p = game.grille[i][j];
			switch (p.get_gem_type()) {
			case 0:
				gem1.setPosition(p.get_abs() + decal.x - taille, p.get_ord() + decal.y - taille);
				app.draw(gem1);
				break;
			case 1:
				gem2.setPosition(p.get_abs() + decal.x - taille, p.get_ord() + decal.y - taille);
				app.draw(gem2);
				break;
			case 2:
				gem3.setPosition(p.get_abs() + decal.x - taille, p.get_ord() + decal.y - taille);
				app.draw(gem3);
				break;
			case 3:
				gem4.setPosition(p.get_abs() + decal.x - taille, p.get_ord() + decal.y - taille);
				app.draw(gem4);
				break;
			case 4:
				gem5.setPosition(p.get_abs() + decal.x - taille, p.get_ord() + decal.y - taille);
				app.draw(gem5);
				break;
			case 5:
				gem6.setPosition(p.get_abs() + decal.x - taille, p.get_ord() + decal.y - taille);
				app.draw(gem6);
				break;
			case 6:
				gem7.setPosition(p.get_abs() + decal.x - taille, p.get_ord() + decal.y - taille);
				app.draw(gem7);
				break;
			}

		}

}

Graphique::~Graphique()
{
}

