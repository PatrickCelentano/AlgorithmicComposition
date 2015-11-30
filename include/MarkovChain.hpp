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
		
		void addOutcome(T, float, T);
		void addOutcome(std::vector<T>, float, T);
		T getOutcome(T input, int seed);
		T getOutcome(std::vector<T> input, int seed);	// Make const later?
		
		MarkovChain(): order(1) {}		// Default constructor (of an order-1 MarkovChain)
		MarkovChain(int o): order(o) {}	// Constructs a new MarkovChain of a given order.
		
	private:
		int order;
		std::map<T,OutcomeSet<T> > matrix;
};

template <typename T>
int MarkovChain<T>::getOrder() const
{
	return order;
}

template <typename T>
void MarkovChain<T>::addOutcome(T input, float weight, T output)
{
	// The size of the input should equal the order
	// of this Markov chain. This is evident from,
	// for instance, the fact that 2,3,4 -> 50% chance
	// 5 would need three numbers (as it is 3rd order)
	if(order != 1)
	{
		std::cerr << "ERROR: MarkovChain: Improper input size!" << std::endl;
	}
	else
	{
		matrix[input].addOutcome(output,weight);
	}
}


/*
template <typename T>
void MarkovChain<T>::addOutcome(std::vector<T> input, float weight, T output)
{
	// The size of the input should equal the order
	// of this Markov chain. This is evident from,
	// for instance, the fact that 2,3,4 -> 50% chance
	// 5 would need three numbers (as it is 3rd order)
	if(input.size() != order)
	{
		std::cerr << "ERROR: MarkovChain: Improper input size!" << std::endl;
	}
	else
	{
		matrix[input].addOutcome(output,weight);
	}
}
*/

template <typename T>
T MarkovChain<T>::getOutcome(T input, int seed)
{
	return matrix[input].getOutcome(seed);
}

/*
template <typename T>
T MarkovChain<T>::getOutcome(std::vector<T> input, int seed) const
{
	return matrix[input].getOutcome(seed);
}
*/

#endif