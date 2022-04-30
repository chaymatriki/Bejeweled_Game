#include "Mode1.h"
#include <vector>


Mode1::Mode1()
{
	for (int i = 0; i <nb; i++)
	{
		levels[i] = i;
		scores[i] = i * 50;
	}
}

const int* Mode1::get_levels() const { return levels; }
const int* Mode1::get_scores() const { return scores; }

int Mode1::get_level(int score) const
{
	int l = 0; bool f = false;
	for (int i = 0; (i< nb) && (!f);)
	{
		if (score < scores[i + 1])
		{
			l = i;
			f = true;
		}
		i++;
	}
	return l;
}

Mode1::~Mode1()
{
}
