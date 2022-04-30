#ifndef DEF_PARTIE
#define DEF_PARTIE
#include "Cellule.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "Joueur.h"
#define n 8         //lignes
#define m 8        //colonnes
#define taille 55     //taille case

class Partie
{
private:
	//Cellule grille[n+1][m+1];   //declared public
	int score_partie;
	int help;
	bool isGameOver;
	int click;
	bool isMoving;
	bool isSwitch;

public:

	Cellule grille[n + 1][m + 1];   //should be private

	Partie();
	const Cellule *get_grille();
	int get_score_partie();
	void set_score_partie(int s);
	int get_help();
	void set_help(int h);
	int get_click();
	void set_click(int c);
	bool get_isGameOver();
	void set_isGameOver(bool o);
	bool get_isMoving();
	void set_isMoving(bool o);
	bool get_isSwitch();
	void set_isSwitch(bool o);
	void recherche();
	void deplacer();
	void maj_grille();
	void initialiser();
	void echanger(Cellule c1, Cellule c2);
	bool aider(int &x, int &y, bool aff);

	~Partie();

};

#endif