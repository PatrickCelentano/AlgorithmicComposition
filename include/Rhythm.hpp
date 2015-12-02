#ifndef __RHYTHM_HPP__
#define __RHYTHM_HPP__

#include <vector>
#include <string>
#include <iostream>

#include "Base.hpp"
#include "Defines.hpp"

////////////////////////////////////////////////
//                  RHYTHM                    //
////////////////////////////////////////////////
// A class representing a string of Counts.   //
////////////////////////////////////////////////
class Rhythm
{
	public:
		unsigned int size() const;	// Gets the number of different counts in this rhythm.
		Count length() const;		// Gets the total length of this rhythm.
		
		Count operator[](unsigned int i) const;
		//Count& operator[](const Count& c) const;
		
		Rhythm operator+(const Count &c);		// Adds a Count to a new Rhythm
		Rhythm& operator+=(const Count &c);		// Adds a Count to this Rhythm
		Rhythm operator+(const Rhythm &r);		// Adds two Rhythms together
		Rhythm& operator+=(const Rhythm &r);	// Adds a Rhythm to this one

		void checkRep() const;				// Ensures this class is valid
		
		Rhythm():							
			totalLength(),
			lengths()
		{
			/*checkRep();*/
		}
			
		Rhythm(const Rhythm &r):
			totalLength(r.totalLength),
			lengths(r.lengths)
		{
			
		}
			
	private:;
		Count totalLength;					// The total length of this rhythm
		std::vector<Count> lengths;			// The notes and rests of this melody
};

#endif