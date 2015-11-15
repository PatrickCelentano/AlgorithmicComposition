#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Defines.hpp"

////////////////////////////////////////////////
//                INTERVAL                    //
////////////////////////////////////////////////
// A class representing a pitch interval.     //
////////////////////////////////////////////////
class Interval
{
	public:
		int getQuality() const;			// Gets the quality of this Interval
		int getNumber() const;			// Gets the number of this Interval
		int getOctaves() const;			// Gets the number of octaves in this interval
		std::string getASCII() const;	// Gets the ASCII string for this pitch
		
		Interval& operator=(const Interval &a);
		
		void checkRep() const;			// Ensures this class is valid
		
		Interval():						// The default constructor
			quality(0), number(1)
			{ checkRep(); }
		Interval(int q, int n):			// A constructor that takes only number and quality
			quality(q), number(n)
			{ checkRep(); }
		Interval(int q, int n, int o):	// A constructor that also takes octaves
			quality(q), number(n + o*7)
			{ checkRep(); }
		
	private:
		int8_t quality;		// The quality of the interval
		int8_t number;		// The number (ie: sixth, third)
};
Interval operator+(const Interval &a, const Interval &b);
Interval operator-(const Interval &a, const Interval &b);
Interval operator+=(const Interval &a, const Interval &b);
Interval operator-=(const Interval &a, const Interval &b);
Interval operator-(const Pitch &a, const Pitch &b);
bool operator==(const Interval &a, const Interval &b);





////////////////////////////////////////////////
//                  PITCH                     //
////////////////////////////////////////////////
// A class representing a single pitch.       //
////////////////////////////////////////////////
class Pitch
{
	public:
		int getClass() const;					// Gets the class of this Pitch
		int getAccidental() const;				// Gets the accidental of this Pitch
		int getOctave() const;					// Gets the octave of this Pitch
		bool isRest() const;					// Gets if this "Pitch" is actually a rest
		std::string getASCII() const;			// Gets the ASCII representation of this note
		std::string getLilyPond() const;		// Gets the "LilyPond" format of this note
		
		Pitch& operator=(const Pitch &a);

		void checkRep() const;					// Ensures this class is valid
		
		Pitch():pClass(C),
				accidental(NATURAL),
				octave(4)						// The default constructor creates a C4
			{ checkRep(); }
		Pitch(int p):pClass(p),
				accidental(NATURAL),
				octave(4)						// The class-only constructor creates an X4
			{ checkRep(); }
		Pitch(int p, int a, int o):				// A constructor taking a pitch class and an octave
			pClass(p),accidental(a),octave(o)
			{ checkRep(); }
		Pitch(const Pitch& p):					// A copy-constructor.
			pClass(p.getClass()),
			accidental(p.getAccidental()),
			octave(p.getOctave())
			{ checkRep(); }

	private:
		int8_t pClass;		// The class of this Pitch
		int8_t accidental;	// Is this pitch sharp/flat/etc
		int8_t octave;		// The octave of this Pitch
};
Pitch operator+(const Pitch &a, const Interval &b);
Pitch operator-(const Pitch &a, const Interval &b);
Pitch operator+=(const Pitch &a, const Interval &b);
Pitch operator-=(const Pitch &a, const Interval &b);
bool operator==(const Pitch &a, const Pitch &b);





////////////////////////////////////////////////
//                  COUNT                     //
////////////////////////////////////////////////
// A class representing time in a musical sen-//
// se. The base unit is the whole note. There //
// is only one valid representation of a beat.//
////////////////////////////////////////////////
class Count
{
	public:
		int getBeat() const;				// Gets the count within the given subdivision
		int getSubdivision() const;			// Gets the subdivision of this note (quarter, half...)
		std::string getASCII() const;		// Returns an ASCII representation of this Count
		std::string getLilyPond() const;	// Returns an LilyPond representation of this Count
		
		void checkRep() const;				// Ensures this class is valid
		
		Count();							// The default constructor creates a 0-beat Count
		Count(int b);						// The one-argument constructor takes in a number of whole notes
		Count(int b, int s);				// The full constructor takes in wholes and subdivision
		Count(const Count& c);				// The copy constructor

	private:
		int beat;			// The number of the given subdivision (the "and" of 1)
		int subdivision;	// The subdivision (quarters, triplets, etc.)
							// Note: these can't be const, due to the complexity of the constructor
};

// These operators allow counts to be combined
Count operator+(const Count &a, const Count &b);
Count operator-(const Count &a, const Count &b);
Count operator+=(const Count &a, const Count &b);
Count operator-=(const Count &a, const Count &b);

// These operators allow augmentation/diminution
Count operator*(const Count &a, int scalar);
Count operator/(const Count &a, int scalar);

// These operators allow comparison
bool operator==(const Count &a, const Count &b);
bool operator>(const Count &a, const Count &b);
bool operator<(const Count &a, const Count &b);
bool operator>=(const Count &a, const Count &b);
bool operator<=(const Count &a, const Count &b);
//Line operator+(const Pitch &a, const Interval &b);





////////////////////////////////////////////////
//                   NOTE                     //
////////////////////////////////////////////////
// A class representing a single note or rest //
////////////////////////////////////////////////
class Note
{
	public:
		Pitch getPitch() const;				// Gets the pitch of this Note
		Count getLength() const;			// Gets the length of this Note in Counts
		bool isRest() const;				// Gets if this "Note" is actually a rest
		std::string getASCII() const;		// Gets the ASCII representation of this Note
		std::string getLilyPond() const;	// Gets the "LilyPond" format of this Note
		
		void checkRep() const;				// Ensures this class is valid
		
		Note(): pitch(),length()
			{ checkRep(); }
		Note(Pitch p, Count l):				// A constructor taking a pitch and a length
			pitch(p),length(l)
			{ checkRep(); }
		Note(const Note& n):					// A copy-constructor.
			pitch(n.getPitch()),
			length(n.getLength())
			{ checkRep(); }

	private:
		Pitch pitch;	// The pitch of this Note (or rest)
		Count length;	// The length of this Note (or rest)
};

#endif