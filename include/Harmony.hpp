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
//                 SONORITY                   //
////////////////////////////////////////////////
// A class representing pitches in a vertical //
// formation, ie: a chord without time.       //
////////////////////////////////////////////////
class Sonority
{
	public:
		void add(Pitch p);						// Adds a Pitch to the Sonority
		Pitch get(int i) const;					// Gets a Pitch from the Sonority
		unsigned int size() const;				// Gets the number of Pitches in this Sonority
		
		bool isRest() const;					// Gets if this Sonority is actually a rest
		int getInversion() const;				// Gets the inversion (ROOT, FIRST_INVERSION, etc)
		int getType() const;					// Gets the quality of this Sonority (MAJOR, MINOR, etc)
		Interval getSpan() const;				// Gets the difference between the highest and lowest Pitch.
		std::string toString() const;			// Gets the ASCII representation of this Sonority
		
		Sonority();								// The default constructor
		Sonority(const Pitch& p, int t);			// A constructor just taking a pitch, and type
		Sonority(const Pitch& p, int t, int i);	// A constructor taking pitch, type, and inversion
		Sonority(std::vector<Pitch> p);			// A constructor taking pitches directly.
		
		void checkRep() const;					// Ensures this class is valid
	
	//FIX THIS!
	//private:
		int type;								// What type of Sonority is this? MAJOR, MINOR, ETC
		Pitch root;								// The root of the Sonority, in the case that it is absent.
		std::vector<Pitch> pitchesByHeight;		// All pitches in the Sonority, stored from highest to lowest.
		std::vector<Pitch> pitchesByDegree;		// All pitches in the Sonority, stored 1st-3rd-5th-7th-etc.
};

Sonority operator+(const Sonority &a, const Interval &b);
Sonority operator-(const Sonority &a, const Interval &b);
Sonority operator+=(const Sonority &a, const Interval &b);
Sonority operator-=(const Sonority &a, const Interval &b);

////////////////////////////////////////////////
//                  CHORD                     //
////////////////////////////////////////////////
// A class representing a single chord, ie: a //
// sonority in time.                          //
////////////////////////////////////////////////
class Chord
{
	public:
		Sonority getSonority() const;		// Gets the Sonority of this Chord
		Count getLength() const;			// Gets the length of this Note in Counts
		bool isRest() const;				// Gets if this "Chord" is actually a rest
		std::string toString() const;		// Gets the ASCII representation of this Chord
		Chord& operator=(const Chord &a);	// An asignment operator.
		
		Chord(): sonority(),length()		// Default constructor
			{	checkRep();	}
		Chord(Sonority s, Count l):			// Constructor with arguments
			sonority(s), length(l)
			{	checkRep();	}
		Chord(const Chord& c):				// Copy constructor
			sonority(c.getSonority()),
			length(c.getLength())
			{	checkRep();	}

	private:
		void checkRep() const;	// Ensures this class is valid
		
		Sonority sonority;		// The pitch of this Note (or rest)
		Count length;			// The length of this Note (or rest)
};

// Chord operations
Chord operator+(const Chord &a, const Interval &b);
Chord operator-(const Chord &a, const Interval &b);
Chord operator+=(const Chord &a, const Interval &b);
Chord operator-=(const Chord &a, const Interval &b);
/*
// These operators allow augmentation/diminution
Chord operator*(const Chord &a, int scalar);
Chord operator/(const Chord &a, int scalar);

// Comparison operations
bool operator==(const Note &a, const Note &b);
*/
/*

////////////////////////////////////////////////
//                 FUNCTION                   //
////////////////////////////////////////////////
// A class representing a chord function.     //
////////////////////////////////////////////////
class Function
{
	public:
		Pitch getRoot() const;					// Gets the root note of this function.
		int getQuality() const;					// Gets the quality of this function's chord (MAJOR, MINOR)
		
		int getInversion() const;				// Gets the inversion (ROOT, FIRST_INVERSION, etc)
		
		Chord getInversion(int i) const;		// Returns the ith inversion chord of this function.
		
		int getQuality() const;					// Gets the quality of this chord (MAJOR, MINOR, etc)
		Interval getSpan() const;				// Gets the difference between the highest and lowest Pitch.
		std::string toString() const;			// Gets the ASCII representation of this chord
		
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
		Scale(Pitch r, int st);					// A constructor, given a root and a "scale type."
		std::string toString() const;			// Gets the ASCII representation of this chord
		
		void checkRep() const;					// Ensures this class is valid
		
	private:
		int scaleType;
		std::vector<Pitch> ascending;			// All the pitches of the scale when ascending
		std::vector<Pitch> descending;			// All the pitches of the scale when descending (still, root at 0)
};

////////////////////////////////////////////////
//                  KEY                       //
////////////////////////////////////////////////
// A class representing a major or minor key. //
////////////////////////////////////////////////
class Key
{
	public:

		Pitch getDegree(int d) const;		// Gets the given scale degree (in the DEFAULT_OCTAVE)
		Sonority getFunction(int d) const;	// Gets the given scale degree (in the DEFAULT_OCTAVE)
		
		Key getParallel() const;			// Returns the parallel major or minor.
		int getQuality() const;				// Gets the quality of this Key
		int getTonic() const;				// Gets the tonic of this Key (in octave 4)
		std::string toString() const;		// Gets the ASCII string for this pitch
		
		void checkRep() const;				// Ensures this class is valid
		
		Key():							// The default constructor
			scale(Scale())
			{ /*checkRep();*/ }
		Key(Pitch p, int q):			// A constructor that also takes octaves
			scale(Scale(p,q))
			{ /*checkRep();*/ }
		
	private:
		Scale scale;	// The scale which best represents the key
};
/*
Key operator+(const Key &a, const Interval &b);
Key operator-(const Key &a, const Interval &b);
Key operator+=(const Key &a, const Interval &b);
Interval operator-=(const Key &a, const Interval &b);
bool operator==(const Key &a, const Key &b);
*/

#endif