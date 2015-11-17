#ifndef __OUTCOME_SET_HPP__
#define __OUTCOME_SET_HPP__

#include <cstdlib>

////////////////////////////////////////////////
//               OUTCOME SET                  //
////////////////////////////////////////////////
// A class used to represent the odds of all  //
// possible outcomes, that, given a seed, ret-//
// urns the actual outcome. Useful for any    //
// probability-based calculations.            //
////////////////////////////////////////////////
template <class T>
class OutcomeSet
{
	public:
		void addOutcome(T value, float weight);
		T getOutcome(int seed) const;
		
		OutcomeSet():			// Default constructor
			totalWeight(0),
			values(),
			weights() {}
	private:
		float totalWeight;
		std::vector<T> values;
		std::vector<float> weights;
};

// Adds a possible outcome,
template <typename T>
void OutcomeSet<T>::addOutcome(T key, float weight)
{
	for(unsigned int i = 0; i < values.size(); i++)
	{
		if(values[i] == key)
		{
			std::cerr << "Error: Added duplicated outcome! " << std::endl;
		}
	}
	// Adds in the new value
	values.push_back(key);
	weights.push_back(totalWeight);
	totalWeight += weight;
}

// Gets the outcome of this OutcomeSet, given a set.
template <typename T>
T OutcomeSet<T>::getOutcome(int seed) const
{
	// Creates a random 
	srand(seed);
	int bestPosition = 0;
	float valueLookingFor = (rand()*totalWeight)/(float)(RAND_MAX);
	
	// Finds the proper value
	for(unsigned int i = 0; i < weights.size(); i++)
	{
		if(valueLookingFor >= weights[i])
		{
			bestPosition = i;
		}
	}
	return values[bestPosition];
}

#endif