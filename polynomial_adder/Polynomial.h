#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include <string>
#include <list>

#include "Term.h"

class Polynomial
{
private:
	std::list<Term> the_data;
public:
	std::string str() const;
	/** string representation of the polynomial */

	const Polynomial operator+ (Polynomial other) const;
	/** sum of two polynomials */

	void parse(const std::string& input);
	/** removes whitespace and then calls global function extract_term (declared in Term.h) for each term */

	void insert_term(const Term& term);
	/** this will insert (in order) if the term with matching exponent isn't already there,
		and add to the term if it's already there,
		then it will delete the term from the_data if the coefficient is zero */
};

#endif  // POLYNOMIAL_H_INCLUDED