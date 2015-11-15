#ifndef __HARMONY_HPP__
#define __HARMONY_HPP__

#include <vector>
#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Defines.hpp"
#include "Base.hpp"

////////////////////////////////////////////////
//                  CHORD                     //
////////////////////////////////////////////////
// A class representing a single chord.       //
////////////////////////////////////////////////
class Chord
{
	public:
		Pitch getRoot() const;					// Gets the root note of this chord.
		int getInversion() const;				// Gets the inversion (ROOT, FIRST_INVERSION, etc)
		int getQuality() const;					// Gets the quality of this chord (MAJOR, MINOR, etc)
		Interval getSpan() const;				// Gets the difference between the highest and lowest Pitch.
		std::string getASCII() const;			// Gets the ASCII representation of this chord
		std::string getLilyPond() const;		// Gets the "LilyPond" format of this chord
		
		Chord();								// The default constructor
		Chord(const Pitch& p, int q);			// A constructor just taking a pitch, and quality
		Chord(const Pitch& p, int q, int i);	// A constructor taking pitch, quality, and inversion
		Chord(std::vector<Pitch> p);			// A constructor taking pitches directly.
		
		void checkRep() const;					// Ensures this class is valid
		
	private:
		const std::vector<Pitch> pitches;		// All pitches in the chord, stored 1st-3rd-5th (regardless of inversion)
		const Pitch bass;						// Stores the lowest pitch in the chord, for easy access
		const Pitch soprano;					// Stores the highest pitch in the chord, for easy access
};
Chord operator+(const Pitch &a, const Chord &b);
Chord operator-(const Pitch &a, const Chord &b);
Chord operator+=(const Pitch &a, const Chord &b);
Chord operator-=(const Pitch &a, const Chord &b);
//bool operator==(const Chord &a, const Chord &b); Ambiguous... Would inversions count? Open/closed?
// Eventually add chords for polychords?

/*
////////////////////////////////////////////////
//                  KEY                       //
////////////////////////////////////////////////
// A class representing a major or minor key. //
////////////////////////////////////////////////
class Key
{
	public:

		int getQuality() const;					// Returns major or minor.
		Pitch getDegree(int d) const;			// Gets the given scale degree (in octave 4)
		Pitch getDegree(int d, int o) const;	// Gets the given scale degree in a given octave
		
		Key getParallel() const;				// Returns the parallel major or minor.
	
	
		int getQuality() const;			// Gets the quality of this Interval
		int getNumber() const;			// Gets the number of this Interval
		int getOctaves() const;			// Gets the number of octaves in this interval
		std::string getASCII() const;	// Gets the ASCII string for this pitch
		
		void checkRep() const;			// Ensures this class is valid
		
		Interval():						// The default constructor
			numSharps(0), number(0)
			{ checkRep(); }
		Interval(int p, int q):	// A constructor that also takes octaves
			p(p), number(q)
			{ checkRep(); }
		
	private:
		int8_t quality;		// The quality of the interval
		int8_t number;		// The number (ie: sixth, third)
};
Key operator+(const Key &a, const Interval &b);
Key operator-(const Key &a, const Interval &b);
Key operator+=(const Key &a, const Interval &b);
Interval operator-=(const Key &a, const Interval &b);
bool operator==(const Key &a, const Key &b);
*/

////////////////////////////////////////////////
//                 SCALE                      //
////////////////////////////////////////////////
// A class representing a musical scale.      //
////////////////////////////////////////////////
class Scale
{
	public:
		Pitch getDegree(int d) const;			// Gets the degree, assuming a start in octave 4
		Pitch getDegree(int d, int p) const;	// Gets the degree, given a previous degree (to determine ascending/descending)
		int getNumDegrees() const;				// The total number of ascending scale degrees (usually 7)
		
		Scale();
		Scale(Pitch r, int st);				// A constructor, given a root and a "scale type."
		std::string getString() const;			// Gets the ASCII representation of this chord
		
		void checkRep() const;					// Ensures this class is valid
		
	private:
		std::vector<Pitch> ascending;			// All the pitches of the scale when ascending
		std::vector<Pitch> descending;			// All the pitches of the scale when descending (still, root at 0)
};

#endif