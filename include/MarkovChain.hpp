#ifndef __MARKOV_CHAIN_HPP__
#define __MARKOV_CHAIN_HPP__

#include <vector>
#include <map>

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <time.h>

#include "Base.hpp"
#include "Form.hpp"
#include "Harmony.hpp"
#include "Defines.hpp"
#include "OutcomeSet.hpp"

/*
////////////////////////////////////////////////
//               MARKOV CHAIN                 //
////////////////////////////////////////////////
// A class used for compositional purposes.   //
// All functions are static, and are meant to //
// be called either from main, or by each oth-//
// er in a full composition.                  //
////////////////////////////////////////////////
template <class T>
class MarkovChain
{
	public:
		int getOrder() const;		// Returns the order of this Markov Chain.
		
		void addOutcome(std::vector<T>, T );
		T getOutcome(std::vector<T> input, int seed) const;
		
		MarkovChain();				// Default constructor (of an order-1 MarkovChain)
		MarkovChain(int o);			// Constructs a new MarkovChain of a given order.
		
	private:
		int order;
		std::map<std::vector<T>,OutcomeSet<T> > matrix;
	private:
		//
};
*/
#endif