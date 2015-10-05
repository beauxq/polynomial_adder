#ifndef TERM_H_INCLUDED
#define TERM_H_INCLUDED

#include <string>

#include "Alt_iss.h"

class Term
{
	friend class Polynomial;  // to add one coefficient to another when exponents are the same
private:
	int coefficient;
	int exponent;
public:
	// ctors
	Term(const int& coef, const int& exp) : coefficient(coef), exponent(exp) {}
	Term() : coefficient(0), exponent(0) {}

	// operator> operator< based only on exponent
	bool operator> (const Term& other) const;
	bool operator< (const Term& other) const;

	// getters
	int get_coefficient() const;
	int get_exponent() const;
	
	std::string str() const;
	/** string representation	example: returns string "3x^2" */
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