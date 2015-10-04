#ifndef TERM_H_INCLUDED
#define TERM_H_INCLUDED
#include <list>

#include "Alt_iss.h"

/*	notes:
	coefficient and exponent
	constructor has 2 parameters, coefficient and exponent (google ctor initialization list) 
	overload > < //needs to be done
	string representation	.str() function  example: returns string "3x^2" */ 

class Term
{
public:
	Term(const int& coef, const int& exp) : coefficient(coef), exponent(exp) {}
	Term operator> (const Term& other);// { return other(); }  // needs to be done
	//const Term operator< (const Term& other); // { return some(); }  // needs to be done
	int coefficient;
	int exponent;
	std::list<int> poly_list();

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