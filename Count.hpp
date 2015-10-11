#ifndef __COUNT_HPP__
#define __COUNT_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Defines.hpp"

// A class time in a musical sense. The base unit is the whole note.
// There is only one valid representation of a beat, with a given
// number of whole-note beats and subdivision.
class Count
{
	public:
		int getBeat() const;			// Gets the count within the given subdivision
		int getSubdivision() const;		// Gets the subdivision og this note (quarter, half...)
		std::string getASCII() const;	// Returns an ASCII representation of this Count
		void repInvariant() const;		// Ensures this class is valid
		
		Count();						// The default constructor creates a 0-beat Count
		Count(int b);					// The one-argument constructor takes in a number of whole notes
		Count(int b, int s);			// The full constructor takes in wholes and subdivision

	private:
		void reduce();					// Reduces the subdivision into its simplest form.
		
		int beat;						// The number of the given subdivision (the "and" of 1)
		int subdivision;				// The subdivision (quarters, triplets, etc.)
};

// These operators allow counts to be combined
Count operator+(const Count &a, const Count &b);
Count operator-(const Count &a, const Count &b);

// These operators allow augmentation/diminution
Count operator*(const Count &a, int scalar);
Count operator/(const Count &a, int scalar);

// These operators allow comparison
bool operator==(const Count &a, const Count &b);
bool operator>(const Count &a, const Count &b);
bool operator<(const Count &a, const Count &b);
bool operator>=(const Count &a, const Count &b);
bool operator<=(const Count &a, const Count &b);

#endif