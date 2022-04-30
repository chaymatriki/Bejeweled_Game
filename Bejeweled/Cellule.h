#ifndef DEF_CELL
#define DEF_CELL
class Cellule
{
private:
	int abs;
	int ord;
	int row;
	int col;
	int gem_type;
	int match;

public:
	Cellule();
	Cellule(int x, int y, int r, int c, int a);

	int get_abs() const;
	void set_abs(int x);

	int get_ord() const;
	void set_ord(int y);

	int get_row() const;
	void set_row(int r);

	int get_col() const;
	void set_col(int c);

	int get_gem_type() const;
	void set_gem_type(int a);

	int get_match() const;
	void set_match(int m);
	~Cellule();
};

#endif