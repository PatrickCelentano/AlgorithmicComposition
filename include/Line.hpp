#ifndef __LINE_HPP__
#define __LINE_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Defines.hpp"

// An MxM Part is a string of EventFrames, which are to be "played"
// by a voice sequentially. (Think horizontally, not vertically)
{
	public:
		
	private:
		
	/*
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
		
		Count length;					// The number of the given subdivision (the "and" of 1)
		Count subdivision;				// The subdivision (quarters, triplets, etc.)
	*/
};
#endif