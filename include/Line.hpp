#ifndef __LINE_HPP__
#define __LINE_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <vector>
#include "Defines.hpp"
#include "Base.hpp"

////////////////////////////////////////////////
//                   LINE                     //
////////////////////////////////////////////////
// A class representing a string of notes.    //
////////////////////////////////////////////////
class Line
{
	public:
		void addNote(Note n);				// Adds a given note to the end of the line.
		Note getNote(int i) const;			// Gets the i-th note in this line.
		int getRestoringForce() const;		// Gets the desire of this line to move in a given direction.
		Count getLength() const;
		
		/*
		Melody getWithNewPitches(Rhythm r)
		Melody getWithNewRhythm(Rhythm r)
		Melody getRetrograde() const;		// Returns a new melody, just played in retrograde
		Melody getInverstion() const;		// Returns a new melody, just played in retrograde
		*/
		void checkRep() const;				// Ensures this class is valid
		
		Line(): restoringForce(0)
			{ /*checkRep();*/ }					// The default constructor.
		
		
		// Analysis methods
		//float const;
	private:;
		Count length;
		std::vector<Note> notes;			// The notes and rests of this melody
		int restoringForce;					// The desire of the line to move in a given direction
};

#endif