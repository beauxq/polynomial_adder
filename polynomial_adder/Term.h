#ifndef TERM_H_INCLUDED
#define TERM_H_INCLUDED

#include "Alt_iss.h"

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

// global function
Term extract_term(Alt_iss& input);
/**
extracts one Term from an istringstream and leaves the istringstream pointing right after that Term
input should only have + - * ^ digits letters
throws invalid_argument otherwise
also throws invalid_argument for empty stream or not .good() stream
all letters are taken as the same variable (3Y+2r = 3x+2x)
*/

#endif  // TERM_H_INCLUDED