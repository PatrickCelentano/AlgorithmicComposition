#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <vector>
#include "Defines.hpp"
#include "Base.hpp"
#include "Harmony.hpp"

////////////////////////////////////////////////
//                   LINE                     //
////////////////////////////////////////////////
// A class representing a string of notes.    //
////////////////////////////////////////////////
class Line
{
	public:
		void add(Note n);					// Adds a given note to the end of the line.
		Note get(int i) const;				// Gets the i-th note in this line.
		Note get(Count c) const;			// Gets the note at Count c;
		int getRestoringForce() const;		// Gets the desire of this line to move in a given direction.
		Count getLength() const;
		std::string toLilyPond() const;		// Gets a string of the LilyPond representation of this Line.
		
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

////////////////////////////////////////////////
//                PROGRESSION                 //
////////////////////////////////////////////////
// A class representing a string of chords.   //
////////////////////////////////////////////////
class Progression
{
	public:
		void add(Chord n);					// Adds a given note to the end of the line.
		Chord get(int i) const;				// Gets the i-th chord in this line.
		Chord get(Count c) const;			// Gets the chord at Count c.
		Count getLength() const;
		std::string toLilyPond() const;		// Gets a string of the LilyPond representation of this Line.
		
		void checkRep() const;				// Ensures this class is valid
		
		Progression()	{ /*checkRep();*/ }		// The default constructor.
		
		
		// Analysis methods
		//float const;
	private:
		Count length;
		std::vector<Chord> chords;			// The notes and rests of this melody
};

////////////////////////////////////////////////
//                  PIECE                     //
////////////////////////////////////////////////
// A class representing a piece of music of   //
// any length- but one that is complete.      //
////////////////////////////////////////////////
class Piece
{
	/*
	public:
		void add(Note n);					// Adds a given note to the end of the line.
		Note get(int i) const;				// Gets the i-th note in this line.
		int getRestoringForce() const;		// Gets the desire of this line to move in a given direction.
		Count getLength() const;
		std::string toLilyPond() const;		// Gets a string of the LilyPond representation of this Line.
		
		void checkRep() const;				// Ensures this class is valid
		
		Line(): restoringForce(0)
			{ checkRep() }					// The default constructor.
		
		
		// Analysis methods
		//float const;
	private:;
		Count length;
		std::vector<Note> notes;			// The notes and rests of this melody
		int restoringForce;					// The desire of the line to move in a given direction
	*/
};

#endif