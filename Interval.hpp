#ifndef __INTERVAL_HPP__
#define __INTERVAL_HPP__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#include <string>
#include <iostream>

#define DIMINISHED (-2)
#define MINOR (-1)
#define PERFECT 0
#define MAJOR 1
#define AUGMENTED 2

// All intervals are POSITIVE
class Interval
{
	public:
		int getQuality() const;					// Gets the quality of this Interval
		int getNumber() const;					// Gets the number of this Interval
		int getOctaves() const;					// Gets the number of octaves in this interval
		
		void repInvariant() const;				// Ensures this class is valid
		
		std::string getASCII() const;			// Gets the ASCII string for this pitch
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