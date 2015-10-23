#ifndef __PASSAGE_HPP__
#define __PASSAGE_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Defines.hpp"

// An MxM Passage represents a musical structure larger than a
// single phrase, but smaller than a Piece. For instance, a trio
// in a march would be a passage, as it contains multiple (often
// repeated) phrases, and is a part of a larger march.
class Passage
{
	public:
		Count getLenth() const;
		
		std::vector<Phrase> getPhrases() const;	// Gets all the phrases in this 
		std::vector<Part> getParts() const;		// Gets all the individual parts of this Piece
		std::vector<Melody> getMotifs() const;	// Gets all the motivic material of this Piece
	
		Count getLength() const;
		Melody getWithNewPitches(Rhythm r)
		Melody getWithNewRhythm(Rhythm r)
		Melody getRetrograde() const;		// Returns a new melody, just played in retrograde
		Melody getInverstion() const;		// Returns a new melody, just played in retrograde
		
		// Analysis methods
		//float const;
	private:
		vector<Event> events;			// The notes and rests of this melody
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