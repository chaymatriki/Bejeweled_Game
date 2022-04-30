#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <time.h>
#include "Cellule.h"
#include "Joueur.h"
#include "Partie.h"
#include "Mode2.h"
#include "Graphique2.h"
#include<iomanip>

using namespace sf;
using namespace std;

Graphique2::Graphique2() : b_score(0)
{
}

template <typename T>
std::string toString(T arg)
{
	std::stringstream ss;
	ss << arg;
	return ss.str();
}

struct Timer {
	sf::Clock mC;
	float runTime;
	bool bPaused;

	Timer() {
		bPaused = false;
		runTime = 0;
		mC.restart();
	}

	void Reset() {
		mC.restart();
		runTime = 0;
		bPaused = false;
	}

	void Start() {
		if (bPaused) {
			mC.restart();
		}
		bPaused = false;
	}

	void Pause() {
		if (!bPaused) {
			runTime += mC.getElapsedTime().asSeconds();
		}
		bPaused = true;
	}

	float GetElapsedSeconds() {
		if (!bPaused) {
			return runTime + mC.getElapsedTime().asSeconds();
		}
		return runTime;
	}
};


void Graphique2::score_fct(Mode2 &game, Joueur &joueur, Text &t_s)
{
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
		{
			game.set_score_partie(game.get_score_partie() + game.grille[i][j].get_match());
			joueur.set_score(joueur.get_score() + game.grille[i][j].get_match());
			t_s.setString(toString<int>(game.get_score_partie()));
		}
}

void Graphique2::check_gameOver(Partie &game)
{
	int x = 0; int y = 0;
	bool test = game.aider(x, y, false);
	if (!test)
	{
		game.set_isGameOver(true);
	}
}

void Graphique2::affiche_fct(Partie &game, RenderWindow &app, Sprite &gem1, Sprite &gem2, Sprite &gem3, Sprite &gem4, Sprite &gem5, Sprite &gem6, Sprite &gem7, Sprite &bg, Sprite &sc, Text &t_s, Vector2i &decal, Sprite &sclock, Text &chrono, Text &game_over, Text &best_score, Text &bs_t, Text &help0, Text &help1, Text &help2)
{
	Graphique::affiche_fct(game, app, gem1, gem2, gem3, gem4, gem5, gem6, gem7, bg, sc, t_s, decal, help0, help1,help2);
	app.draw(sclock);
	app.draw(chrono);
	app.draw(game_over);
	app.draw(bs_t);
	app.draw(best_score);
	app.display();
}

void Graphique2::main_fct()
{
	srand(time(0));
	Joueur joueur("Guest");
	Mode2 game;
	Texture t0, t1, t2, t3, t4, t5, t6, t7, sc,clock;
	load_textures_fct(t0, t1, t2, t3, t4, t5, t6, t7, sc);
	clock.loadFromFile("images/clock.png");
	Sprite background(t0), gem1(t1), gem2(t2), gem3(t3), gem4(t4), gem5(t5), gem6(t6), gem7(t7), score(sc),sclock(clock);
	sf::Font font;
	Text text_score, best_score, bs_t, game_over,chrono,help0,help1,help2;
	Timer h,h2;
	Vector2i decal(250, 50);
	Vector2i position;
	int x1 = 0; int y1 = 0; int x2 = 0; int y2 = 0;

	help0.setFont(font);
	help0.setPosition(620, 5);
	help0.setCharacterSize(14);
	help0.setString("Press \"h\" for help");
	help1.setFont(font);
	help1.setPosition(40, 10);
	help1.setCharacterSize(18);
	help1.setString("Help = 3");
	help2.setFont(font);
	help2.setPosition(300, 10);
	help2.setCharacterSize(18);
	help2.setString("");
	score.setPosition(20, 50);
	sclock.setPosition(30, 180);
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "   Error occured while loading font   " << std::endl;
	}
	text_score.setFont(font);
	text_score.setPosition(100, 60);
	best_score.setFont(font);
	best_score.setPosition(100, 430);
	bs_t.setFont(font);
	bs_t.setPosition(30, 390);
	bs_t.setString("BEST SCORE : ");
	best_score.setString(toString<int>(b_score));
	chrono.setFont(font);
	chrono.setFillColor(Color::White);
	chrono.setPosition(120, 270);
	game_over.setFont(font);
	game_over.setPosition(250, 200);
	game_over.setString("");
	game_over.setCharacterSize(72);

	game.initialiser();


	RenderWindow app(VideoMode(750, 500), "Bejeweled"); //open a window of size 800x500px //Render window specialized class for graphics inherits from class window
	app.setFramerateLimit(60);        //to control the framerate //application to run at a given framerate, instead of the monitor's frequency	

									  //Cellule grid[n + 1][m + 1];

	while (app.isOpen()) //while the window is still open
	{
		//grid = game.get_grille();            //retry this later
		int click = game.get_click();
		h.Start();
		h2.Start();
		if (h.GetElapsedSeconds() > game.get_temps())
		{
			h.Pause();
			game_over.setString("GAME OVER");
			game.set_isGameOver(true);
			if (game.get_score_partie() > b_score)
			{
				b_score=game.get_score_partie();
			}
		}
		else
		{
			chrono.setString(toString<int>((int)h.GetElapsedSeconds()));
		}
		if (h2.GetElapsedSeconds() > 6)
		{
			help2.setString("");
			h2.Reset();
		}
		Event e;
		while (app.pollEvent(e)) //joue le rôle d'un Event Listener
		{
			if (e.type == Event::Closed)  //closes the game window if close button is hit
				app.close();

			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
				{
					if (!game.get_isGameOver())
					{
						if (!game.get_isSwitch() && !game.get_isMoving())
							game.set_click(++click);
						position = Mouse::getPosition(app) - decal;
					}
				}
			if (e.type == Event::KeyReleased)
			{
				if (e.key.code == Keyboard::H) //gestion de clavier
				{
					// appel fct aider de Partie si aide > 0

					if (game.get_help()) {
						int h = game.get_help();
						int lig = -1; int col = -1;
						game.aider(lig, col, true);
						game.set_help(--h);
						help2.setString("indice : ligne = " + toString<int>(lig) + " , colonne = " + toString<int>(col));
						help1.setString("Help = " + toString<int>(game.get_help()));
					}
					else
					{
						help1.setString("Help not available ");
					}
				}
			}
		}

		// appel fct click
		click_fct(click, x1, y1, x2, y2, position, game);

		//appel fct recherche de Partie (si il y a des alignements de 3 ou plus)
		game.recherche();

		// appel fct deplacer de Partie
		game.deplacer();

		//appel fct calcul score
		score_fct(game, joueur, text_score);

		//appel fct check
		check(game, x1, y1, x2, y2),

		//appel fct mise à jour grille
		game.maj_grille();

		//appel fct affichage de l'interface
		affiche_fct(game, app, gem1, gem2, gem3, gem4, gem5, gem6, gem7, background, score, text_score, decal, sclock, chrono, game_over, best_score, bs_t,help0,help1,help2);

		//appel fct check si game over ou non
		check_gameOver(game);
	}
}

Graphique2::~Graphique2()
{
}
