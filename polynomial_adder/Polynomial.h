#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include <string>

#include "Term.h"

/*	notes:
	list of Terms (use c++ built-in  std::list<Term> )
	add_term (this will insert (in order) if the term with matching exponent isn't already there,
		and add to the term if it's already there,
		then it will delete the term if the coefficient is zero)
	overload operator+ to add two polynomials (just make a new Polynomial and add_term for every term in both of the originals)
	*/

class Polynomial
{
public:
	std::string str() const { return "3x^2"; }  // placeholder for testing
	const Polynomial operator+ (const Polynomial& other) { return Polynomial(); }  // placeholder //needs to be done
	void parse(const std::string& input); //done
	void add_term(const Term& term) {}  // {} placeholder //needs to be done
};

#endif  // POLYNOMIAL_H_INCLUDED