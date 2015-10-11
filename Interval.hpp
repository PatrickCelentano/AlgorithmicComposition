#ifndef __INTERVAL_HPP__
#define __INTERVAL_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Defines.hpp"

// All intervals are POSITIVE
class Interval
{
	public:
		int getQuality() const;					// Gets the quality of this Interval
		int getNumber() const;					// Gets the number of this Interval
		int getOctaves() const;					// Gets the number of octaves in this interval
		std::string getASCII() const;			// Gets the ASCII string for this pitch
		
		void repInvariant() const;				// Ensures this class is valid
		
		Interval(int q, int n):					// A constructor that takes only number and quality
			quality(q), number(n)
			{ repInvariant(); }
		Interval(int q, int n, int o):			// A constructor that also takes octaves
			quality(q), number(n + o*7)
			{ repInvariant(); }
		
	private:
		int8_t quality;		// The quality of the interval
		int8_t number;		// The number (ie: sixth, third)
};
#endif