#ifndef DEF_MODE1
#define DEF_MODE1
#define nb 30
#include <vector>
#include "Partie.h"

class Mode1 : public Partie
{
private:
	int levels[nb];
	int scores[nb];

public:
	Mode1();

	const int *get_levels() const;
	const int *get_scores() const;
	int get_level(int score) const;

	~Mode1();
};

#endif