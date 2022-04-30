#include "Partie.h"
#include "Cellule.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include<iterator>

Partie::Partie() : score_partie(0), isGameOver(false), help(3), click(0), isMoving(false), isSwitch(false)
{

}


void Partie::initialiser()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			Cellule c(j*taille, i*taille, i, j, rand() % 7);
			grille[i][j] = c;
		}
}


void Partie::echanger(Cellule c1, Cellule c2)
{
	int a, b, c, d, temp1, temp2;
	a = c1.get_col();
	b = c2.get_col();
	c = c1.get_row();
	d = c2.get_row();

	temp1 = a;
	a = b;
	b = temp1;

	temp2 = c;
	c = d;
	d = temp2;

	grille[c][a].set_abs(c1.get_abs());
	grille[c][a].set_ord(c1.get_ord());
	grille[c][a].set_gem_type(c1.get_gem_type());
	grille[c][a].set_match(c1.get_match());

	grille[d][b].set_abs(c2.get_abs());
	grille[d][b].set_ord(c2.get_ord());
	grille[d][b].set_gem_type(c2.get_gem_type());
	grille[d][b].set_match(c2.get_match());

}

void Partie::deplacer()
{
	isMoving = false;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			Cellule &p = grille[i][j];
			if (p.get_abs() != p.get_col()*taille)
				p.set_abs(p.get_col()*taille);

			if (p.get_ord() != p.get_row()*taille)
				p.set_ord(p.get_row()*taille);
		}
}


void Partie::maj_grille()
{
	if (!isMoving)
	{
		for (int i = n; i>0; i--)
			for (int j = 1; j <= m; j++)
				if (grille[i][j].get_match())
					for (int k = i; k>0; k--)
						if (!grille[k][j].get_match()) { echanger(grille[k][j], grille[i][j]); break; };

		for (int j = 1; j <= m; j++)
			for (int i = n, k = 0; i>0; i--)
				if (grille[i][j].get_match())
				{
					grille[i][j].set_gem_type(rand() % 7);
					grille[i][j].set_ord(-taille*k++);
					grille[i][j].set_match(0);		
				}
	}
}


const Cellule* Partie::get_grille() { return *this->grille; }

void Partie::recherche()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (grille[i][j].get_gem_type() == grille[i + 1][j].get_gem_type())
				if (grille[i][j].get_gem_type() == grille[i - 1][j].get_gem_type())
					for (int k = -1; k <= 1; k++)
					{
						int a = grille[i + k][j].get_match();
						grille[i + k][j].set_match(++a);
					}

			if (grille[i][j].get_gem_type() == grille[i][j + 1].get_gem_type())
				if (grille[i][j].get_gem_type() == grille[i][j - 1].get_gem_type())
					for (int k = -1; k <= 1; k++)
					{
						int a = grille[i][j + k].get_match();
						grille[i][j + k].set_match(++a);
					}
		}
}

bool Partie::aider(int &x, int &y, bool aff)
{
	bool test = false;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!test)
			{
				if ((!test) && (grille[i][j - 1].get_gem_type() == grille[i][j + 1].get_gem_type()) && (1 <= (j - 1) && (j - 1) <= m) && (1 <= (j + 1) && (j + 1) <= m)) {

					if ((!test) && (grille[i - 1][j].get_gem_type() == grille[i][j - 1].get_gem_type()) && (1 <= (i - 1) && (i - 1) <= m) && (1 <= (j - 1) && (j - 1) <= m)) {
						//std::cout << "fama mekla fel weset bel 3aredh      " << i << "  " << j << std::endl;
						 if (aff) { x = i; y = j; }
						test = true;
					}
					else if ((!test) && (grille[i + 1][j].get_gem_type() == grille[i][j - 1].get_gem_type()) && (1 <= (i + 1) && (i + 1) <= m) && (1 <= (j - 1) && (j - 1) <= m)) {
						//std::cout << "fama mekla fel weset bel 3aredh     " << i << "  " << j << std::endl;
						x = i; y = j;
						test = true;
					}
				}
				else if ((!test) && (grille[i - 1][j].get_gem_type() == grille[i + 1][j].get_gem_type()) && (1 <= (i - 1) && (i - 1) <= m) && (1 <= (i + 1) && (i + 1) <= m)) {
					if ((!test) && (grille[i][j - 1].get_gem_type() == grille[i + 1][j].get_gem_type()) && (1 <= (i + 1) && (i + 1) <= m) && (1 <= (j - 1) && (j - 1) <= m)) {
						//std::cout << "fama mekla fel weset bel toul     " << i << "  " << j << std::endl;
						x = i; y = j;
						test = true;
					}
					else if ((!test) && (grille[i][j + 1].get_gem_type() == grille[i + 1][j].get_gem_type()) && (1 <= (i + 1) && (i + 1) <= m) && (1 <= (j + 1) && (j + 1) <= m)) {
						//std::cout << "fama mekla fel weset bel toul    " << i << "  " << j << std::endl;
						x = i; y = j;
						test = true;
					}
				}
			}
		}
	}
	int num[2] = { 1, -1 };
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!test)
			{
				for (int a : num) {
					if ((!test) && (grille[i][j].get_gem_type() == grille[i + a][j].get_gem_type()) && (1 <= (i + a) && (i + a) <= m)) {

						for (int var : num) {
							if ((!test) && (grille[i][j].get_gem_type() == grille[i + a + a][j + var].get_gem_type()) && (1 <= (i + a + a) && (i + a + a) <= m) && (1 <= (j + var) && (j + var) <= n)) {
								//std::cout << "fama mekla mtaa zouz bejnab baadhhom bel toul    " << i + a + a << "  " << j << std::endl;
								x = i + a + a; y = j;
								test = true;
							}
						}
						if ((!test) && (grille[i][j].get_gem_type() == grille[i + a + a + a][j].get_gem_type()) && (1 <= (i + a + a + a) && (i + a + a + a) <= m)) {
							//std::cout << "fama mekla mtaa zouz bejnab baadhhom bel toul    " << i + a + a << "  " << j << std::endl;
							x = i + a + a; y = j;
							test = true;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!test)
			{
				for (int a : num) {
					if ((!test) && (grille[i][j].get_gem_type() == grille[i][j + a].get_gem_type()) && (1 <= (j + a) && (j + a) <= m)) {

						for (int var : num) {
							if ((!test) && (grille[i][j].get_gem_type() == grille[i + var][j + a + a].get_gem_type()) && (1 <= (j + a + a) && (j + a + a) <= m) && (1 <= (i + var) && (i + var) <= n)) {
								//std::cout << "fama mekla mtaa zouz bejnab baadhhom bel 3aredh   " << i << "  " << j + a + a << std::endl;
								x = i; y = j + a + a;
								test = true;
							}
						}
						if ((!test) && (grille[i][j].get_gem_type() == grille[i][j + a + a + a].get_gem_type()) && (1 <= (j + a + a + a) && (j + a + a + a) <= m)) {
							//std::cout << "fama mekla mtaa zouz bejnab baadhhom bel 3aredh    " << i << "  " << j + a + a << std::endl;
							x = i; y = j + a + a;
							test = true;
						}
					}
				}
			}
		}
	}
	return test;
}


//Cellule** Partie::get() { return this.grille; }

int Partie::get_score_partie() { return score_partie; }
void Partie::set_score_partie(int s) { score_partie = s; }
int Partie::get_help() { return help; }
void Partie::set_help(int h) { help = h; }
int Partie::get_click() { return click; }
void Partie::set_click(int c) { click = c; }
bool Partie::get_isGameOver() { return isGameOver; }
void Partie::set_isGameOver(bool o) { isGameOver = o; }
bool Partie::get_isMoving() { return isMoving; }
void Partie::set_isMoving(bool o) { isMoving = o; }
bool Partie::get_isSwitch() { return isSwitch; }
void Partie::set_isSwitch(bool o) { isSwitch = o; }

Partie::~Partie()
{
}
