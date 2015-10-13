#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Polynomial.h"

class Menu
{
private:
	Polynomial p1, p2;

	static void input_polynomial(Polynomial& which_polynomial);
public:
	bool run();  // returns false for quit, true otherwise
};

#endif  // MENU_H_INCLUDED