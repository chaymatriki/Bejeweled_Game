#ifndef DEF_JOUEUR
#define DEF_JOUEUR
#include <string>

class Joueur
{
private:
	const int id;
	std::string nom;
	int level;
	int score;
	//int best_score;


public:
	Joueur();
	Joueur(std::string nom);

	int get_id() const;

	std::string get_nom() const;
	void set_nom(std::string nom);

	int get_level() const;
	void set_level(int level);

	int get_score() const;
	void set_score(int score);

	//int get_best_score() const;
	//void set_best_score(int score);

	~Joueur();
};

#endif
