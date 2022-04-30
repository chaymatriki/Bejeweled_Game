#ifndef DEF_MODE2
#define DEF_MODE2
#define t 90       //30 secondes par défaut
#include "Partie.h"

class Mode2 : public Partie
{
private:
	int temps;
public:
	Mode2();

	int get_temps() const;
	void set_temps(int p);

	~Mode2();
};

#endif