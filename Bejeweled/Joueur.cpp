#include "Joueur.h"


Joueur::Joueur() : id(rand()), level(0), score(0), nom("guest") {}
Joueur::Joueur(std::string name) : id(rand()), level(0), score(0),nom(name){}

int Joueur::get_id() const { return id; }
std::string Joueur::get_nom() const	{ return nom; }
void Joueur::set_nom(std::string name) { nom = name;	}
int Joueur::get_level() const { return level; }
void Joueur::set_level(int lvl) { level = lvl; }
int Joueur::get_score() const { return score; }
void Joueur::set_score(int scr)	{ score = scr; }
//int Joueur::get_best_score() const { return best_score; }
//void Joueur::set_best_score(int b_score) { best_score = b_score; }

Joueur::~Joueur() {}
