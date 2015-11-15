#include "Harmony.hpp"
/*
Pitch getRoot() const;					// Gets the root note of this chord.
int getInversion() const;				// Gets the inversion (ROOT, FIRST_INVERSION, etc)
int getQuality() const;					// Gets the quality of this chord (MAJOR, MINOR, etc)
Interval getSpan() const;				// Gets the difference between the highest and lowest Pitch.
std::string getASCII() const;			// Gets the ASCII representation of this chord
std::string getLilyPond() const;		// Gets the "LilyPond" format of this chord

Chord();								// The default constructor
Chord(const Pitch& p, int q);			// A constructor just taking a pitch, and quality
Chord(const Pitch& p, int q, int i);	// A constructor taking pitch, quality, and inversion
Chord(const Pitch p[]);					// A constructor taking pitches directly.

void checkRep() const;					// Ensures this class is valid

private:
const int numPitches;					// The number of independent pitches in this chord
const Pitch pitches[];					// All pitches in the chord, stored 1st-3rd-5th (regardless of inversion)
const Pitch bass;						// Stores the lowest pitch in the chord, for easy access
const Pitch soprano;					// Stores the highest pitch in the chord, for easy access
*/
/*
Chord::Chord()
{
	
}

Chord::Chord()
{
	
}

Chord::Chord()
{
	
}

Chord::Chord(std::vector<Pitch> p)
{
	// We can't trust that these
	// are in any sort of order when
	// we get them, so we have to
	// look at the relationships
	// between notes and look for
	// a root.
	
	// Start by c
	pitches = p;
}*/