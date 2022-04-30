#include "Cellule.h"



Cellule::Cellule() : abs(0), ord(0), row(0), col(0), gem_type(0), match(0) {}
Cellule::Cellule(int x, int y, int r, int c, int a) : match(0) { abs = x; ord = y; row = r; col = c; gem_type = a; }

int Cellule::get_abs() const { return abs; }
void Cellule::set_abs(int x) { abs = x; }
int Cellule::get_ord() const { return ord; }
void Cellule::set_ord(int y) { ord = y; }
int Cellule::get_row() const { return row; }
void Cellule::set_row(int r) { row = r; }
int Cellule::get_col() const { return col; }
void Cellule::set_col(int c) { col = c; }
int Cellule::get_gem_type() const { return gem_type; }
void Cellule::set_gem_type(int a) { gem_type = a; }
int Cellule::get_match() const { return match; }
void Cellule::set_match(int m) { match = m; }

Cellule::~Cellule()
{
}
