#ifndef TERM_H_INCLUDED
#define TERM_H_INCLUDED

/*	notes:
	coefficient and exponent
	constructor has 2 parameters, coefficient and exponent (google ctor initialization list)
	overload > <
	string representation	.str() function  example: returns string "3x^2" */

class Term
{
public:
	Term(int coef, int exp) : coefficient(coef), exponent(exp) {}

	int coefficient;
	int exponent;
};

#endif  // TERM_H_INCLUDED